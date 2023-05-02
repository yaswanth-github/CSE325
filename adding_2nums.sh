#!/bin/sh

echo "Adding of Two Numbers"
echo "Enter Number 1:"
read a
echo "Enter Number 2:"
read b
d=$(($a+$b))
echo "Sum of two numbers $a+$b=$d"
