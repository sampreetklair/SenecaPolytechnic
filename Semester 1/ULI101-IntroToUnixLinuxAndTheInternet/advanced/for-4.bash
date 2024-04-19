#!/bin/bash
clear
set $(ls)
echo "Here are files in my current directory:"
echo
for x
do
   echo "    $x"
done
