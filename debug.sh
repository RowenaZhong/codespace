#!/bin/bash
vim $1.in && ./$1.app $$ echo && echo output: && more $1.out
