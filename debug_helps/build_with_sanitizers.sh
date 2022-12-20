#!/bin/bash

# ref:
# g++ -ggdb -fsanitize=address -fno-omit-frame-pointer -lrt fly.cc -o fly.out
# static build: -static-libstdc++ -static-libasan  

g++ -ggdb -fno-omit-frame-pointer -fsanitize=address fly.cc -o fly.out
# -fsanitize=leak
# -fsanitize=thread

# For details refer to https://github.com/google/sanitizers/wiki/AddressSanitizer