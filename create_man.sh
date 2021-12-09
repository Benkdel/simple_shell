#!/bin/bash
cp man_1_simple_shell man_1_simple_shell.1
gzip -q man_1_simple_shell.1
sudo mv man_1_simple_shell.1.gz /usr/share/man/man1/
man man_1_simple_shell 1
