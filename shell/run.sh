#!/bin/bash
time ./$1 $$ echo && echo output: && more $1.out
