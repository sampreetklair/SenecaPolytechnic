#!/bin/bash

if [ $# -ne 1 ]
then
  echo "USAGE: $0 [arg]" >&2
  exit 1
fi

echo "The argument is: $1"
