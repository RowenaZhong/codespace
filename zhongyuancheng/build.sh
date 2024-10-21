#!/bin/bash
g++ -o $1.app -x c++ $1.cpp -lm -O2 -DONLINE_JUDGE -std=c++14


