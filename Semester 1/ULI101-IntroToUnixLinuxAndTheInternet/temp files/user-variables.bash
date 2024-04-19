#!/bin/bash
age=25
readonly age
read -p "Enter your Full Name: " name
read -p "Enter your age (in years): " age
echo "Hello $name - You are $age years old"
