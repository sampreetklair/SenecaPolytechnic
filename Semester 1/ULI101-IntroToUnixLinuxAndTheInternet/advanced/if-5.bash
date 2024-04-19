#!/bin/bash
clear
read -p "Enter a mark (0-100): " mark
while ! echo $mark | egrep "^[0-9]{1,}$" > /dev/null 2> /dev/null
do
   read -p "Not a valid number. Enter a mark (0-100): " mark
done
while [ $mark -lt 0 ] || [ $mark -gt 100 ]
do
   read -p "Invalid number range. Enter a mark (0-100): " mark
done
if [ $mark -ge 80 ]
then
   echo "You received an A grade."
elif [ $mark -ge 70 ]
then
   echo "You received a B grade."
elif [ $mark -ge 60 ]
then
   echo "You received a C grade."
elif [ $mark -ge 50 ]
then
   echo "You received a D grade."
else
   echo "You received an F grade."
fi
