#include <iostream>
#include <atomic>

template<typename _Ty>
class LockFreeStackT
{
public:
  struct Node
  {
    _Ty val;
    Node* next;
  };

  LockFreeStackT() : head_(nullptr) {}

  void push(const _Ty& val)
  {
    Node* node = new Node{ val, head_.load() };
    while (!head_.compare_exchange_strong(node->next, node)) {
    }
  }

  void pop()
  {
    Node* node = head_.load();
    while (node && !head_.compare_exchange_strong(node, node->next)) {
    }
    if (node) delete node;
  }

private:
  std::atomic<Node*> head_;
};