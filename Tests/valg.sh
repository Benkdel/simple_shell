#!/bin/bash

gcc -g -Wall -Wextra -Werror -pedantic -std=gnu89 ../*.c -o hsh;

valgrind --leak-check=full --leak-check=yes -s --track-origins=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./hsh
