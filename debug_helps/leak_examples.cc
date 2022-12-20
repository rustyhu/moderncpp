#include <iostream>

int heap_leak_fn() {
  int* a = new int[10];
  // also no init
  std::cout << a[0] << std::endl;
  return 0;
}

int heap_use_after_free_fn() {
  int* a = new int[10];
  // also no init
  delete[] a;
  std::cout << a[0] << std::endl;
  return 0;
}

int heap_buffer_overflow_fn() {
  int* a = new int[10];
  // also no init
  std::cout << a[0] << std::endl;
  return a[10];
}

int stack_buffer_overflow_fn() {
  int a[10];
  std::cout << a[0] << std::endl;
  return a[10];
}

int g_a[10];
int global_buffer_overflow_fn() {
  std::cout << g_a[0] << std::endl;
  return g_a[10];
}

int main() {
  heap_leak_fn();
  // heap_use_after_free_fn();
  // heap_buffer_overflow_fn();

  // auto i = stack_buffer_overflow_fn();
  auto j = global_buffer_overflow_fn();
  std::cout << "Print the j: " << j << "\n";
}