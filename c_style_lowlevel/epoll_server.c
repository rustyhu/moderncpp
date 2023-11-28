#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

static const int BUFLEN = 1024;

bool special_recv_opr(int rfd) {
  char buf[BUFLEN];
  int ret = recv(rfd, buf, BUFLEN, 0);
  if (ret == -1) {
    perror("recv");
    close(rfd);
    return false;
  } else if (ret == 0) {
    // closed? need to delete this fd
    close(rfd);
    return false;
  } else {
    if (ret == BUFLEN) ret -= 1;  // buf is full, no '\0'
    buf[ret] = '\0';
    printf("recv: [%s]\n", buf);
  }
  return true;
}

bool special_send_opr(int wfd) {
  int ret = send(wfd, "hello world!", 13, 0);
  if (ret == -1) {
    perror("send");
  }
  return true;
}

static const int DSCP_SIZE = 16;

int main() {
  // write a epoll server
  int epoll_fd = epoll_create(DSCP_SIZE);
  if (epoll_fd == -1) {
    perror("epoll_create");
    exit(EXIT_FAILURE);
  }

  int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (listen_fd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }
  if (listen(listen_fd, DSCP_SIZE) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  struct epoll_event ev;
  ev.events = EPOLLIN | EPOLLOUT;
  ev.data.fd = listen_fd;
  if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &ev) == -1) {
    perror("epoll_ctl: listen_sock");
    exit(EXIT_FAILURE);
  }

  struct epoll_event events[DSCP_SIZE];
  while (true) {
    int nfds = epoll_wait(epoll_fd, events, DSCP_SIZE, -1);
    if (nfds == -1) {
      perror("epoll_wait");
    }

    for (int n = 0; n < nfds; ++n) {
      if (events[n].data.fd == listen_fd) {
        // listen get something, accept a new connection
        int nconn = accept(listen_fd, NULL, NULL);
        if (nconn == -1) {
          perror("accept");
          exit(EXIT_FAILURE);
        }
        // add new connection to epoll
        ev.events = EPOLLIN;
        ev.data.fd = nconn;
        if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, nconn, &ev) == -1) {
          perror("epoll_ctl: nconn");
          exit(EXIT_FAILURE);
        }
      } else {
        // recv in
        if ((events[n].events & EPOLLIN) > 0) {
          int rfd = events[n].data.fd;
          if (special_recv_opr(rfd)) {
            ev.events = EPOLLOUT;
            ev.data.fd = rfd;
            epoll_ctl(epoll_fd, EPOLL_CTL_MOD, rfd, &ev);
          } else {
            epoll_ctl(epoll_fd, EPOLL_CTL_DEL, rfd, NULL);
          }
        }
        // send out
        if ((events[n].events & EPOLLOUT) > 0) {
          int wfd = events[n].data.fd;
          special_send_opr(wfd);
          close(wfd);
          epoll_ctl(epoll_fd, EPOLL_CTL_DEL, wfd, NULL);
        }
      }
    }
  }

  close(epoll_fd);
  return 0;
}
