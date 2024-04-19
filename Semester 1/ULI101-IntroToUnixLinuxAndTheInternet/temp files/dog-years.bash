#!/bin/bash
echo
dogFactor=7
read -p "Please enter your age (in years): " humanYears
((dogYears = humanYears * dogFactor))
echo "You age in dog-years is: $dogYears"
echo
