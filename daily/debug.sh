#!/bin/bash
vim $1.in && time ./$1 $$ echo && echo output: && more $1.out
