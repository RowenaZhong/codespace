#!/bin/bash
./$1.app $$ echo && echo output: && more $1.out
