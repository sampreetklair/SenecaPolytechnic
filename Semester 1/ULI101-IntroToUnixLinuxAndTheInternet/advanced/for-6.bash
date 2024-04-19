#!/bin/bash
value=1
while [ $value -le 5 ]
do
  echo "$value"
  ((value=value+1))
done
