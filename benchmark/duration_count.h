#ifndef DURATION_COUNT_H
#define DURATION_COUNT_H

#include <functional>

void addBenchmark(std::function<void()> f);

template <typename F, typename... ARG>
void addBenchmarkTmpl(F f, ARG &&... arg);

#endif