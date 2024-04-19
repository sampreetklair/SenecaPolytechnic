#!/bin/bash
echo
echo "Hello $USER"
echo
echo "The current shell you are using is: $(ps -o cmd= -p $$|cut -d' ' -f1)"
echo
echo "The current directory location is: $PWD"
echo "The current user home directory is: $HOME"
echo
