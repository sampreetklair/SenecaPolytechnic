#!/bin/bash

for x
do

  if [ $x = "uli101" ]
  then
     break
  fi
  echo "Argument is: $x"
done

echo
echo "Shell script has been completed"

