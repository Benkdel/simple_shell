#!/bin/bash

file=$1
task=$2

gcc -g $file


valgrind --leak-check=full --leak-check=yes -s --track-origins=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./a.out $task
