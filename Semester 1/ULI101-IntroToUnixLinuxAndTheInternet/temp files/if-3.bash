#!/bin/bash
read -p "Enter the first number: " num1
read -p "Enter the second number: " num2
if [ $num1 -gt $num2 ]
then
   echo "The first number is greater than the second number."
else
   echo "The first number is less than or equal to the second number."
fi
