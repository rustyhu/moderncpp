#include <stdio.h>
#include <stdlib.h>

int countlines(const char *filename) {
  // count the number of lines in the file called filename
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) return 0;

  int ch = 0;
  int lines = 1;

  // take care of `feof()`!
  // https://stackoverflow.com/questions/5431941/why-is-while-feof-file-always-wrong
  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\n') lines++;
  }
  // when ch == EOF
  if (ferror(fp)) {
    printf("File read error!");
  }

  fclose(fp);
  return lines;
}

int main(int argc, char *argv[]) { printf("LINES: %d\n", countlines("oop.c")); }
