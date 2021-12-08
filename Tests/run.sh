#!/bin/bash

task=$1

gcc -g -Wall -Wextra -Werror -pedantic -std=gnu89 ../*.c -o hsh;

./hsh $task
