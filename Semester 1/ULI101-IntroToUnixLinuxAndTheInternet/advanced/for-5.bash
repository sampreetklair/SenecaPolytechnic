#!/bin/bash
clear
echo "Here are files in my current directory:"
echo
for x in $(ls)
do
   echo "    $x"
done
