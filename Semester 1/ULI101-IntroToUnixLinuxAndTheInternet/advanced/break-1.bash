#!/bin/bash

read -p "Enter an integer: " number

while ! echo $number | egrep "^[0-9]{1,}$" > /dev/null 2> /dev/null || [ $number -ne 5 ] 2> /dev/null
do
  if [ $number -eq 5 ] 2> /dev/null
  then
     break
  fi
  read -p "Try again. Enter a valid integer: " number
done

echo "The number is: $number"

