#!/bin/sh

echo "enter 1st number:"
read a
echo "enter 2nd number:"
read b
echo "enter which operation do you want from below:"
echo "1 For Addions"
echo "2 For Subtraction"
echo "3 For Multiplication"
echo "4 For Division"
read opp

case $opp in
        1)echo "$(($a+$b))";;
        2)echo "$(($a-$b))";;
        3)echo "$(($a*$b))";;
	4)echo "$(echo "$a / $b" | bc -l)";;
        *)echo Invalid Input Try Again;;
esac
