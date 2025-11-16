#!/bin/bash
cp data/$1$2.in $1.in
time ./$1 < $1.in > $1.out
diff $1.out data/$1$2.ans -w
