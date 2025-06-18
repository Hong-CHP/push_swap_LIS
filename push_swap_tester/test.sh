#!/bin/bash

size="$1"
if [ -z "$size" ]; then
	echo -e "./test.sh <size of the numbers array>"
	exit 1
fi

params=$(python3 generate.py "$size")

check_leak() {
	valgrind ../push_swap $params 2>&1 | grep "ERROR SUMMARY"
}

moves() {
	../push_swap $params | wc -l
}

sorted() {
	../push_swap $params | ../checker_linux $params
}


moves
sorted
check_leak
