#!/bin/bash

export ARG=$(./a.out)
echo "input  = $ARG"
echo -n "result = "
export ARG=$(./rubik "$ARG")
echo $ARG
echo -n "count  = "
echo $ARG | wc -w
# unset ARG