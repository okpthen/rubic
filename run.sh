#!/bin/bash

export ARG=$(./a.out 10)
echo "input  = $ARG"
echo -n "result = "
export ARG1=$(./rubik "$ARG")
echo $ARG1
echo -n "count  = "
echo $ARG1 | wc -w
echo "$ARG $ARG1"
# unset ARG ARG1
# echo "https://rubiks-cube-solver.com/"