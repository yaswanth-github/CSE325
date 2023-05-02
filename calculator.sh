#!/bin/sh

echo "Calculator"
echo " "

echo "enter 1st number:"
read a
echo "enter 2nd number:"
read b
echo "enter which operation do you want from below:"
echo "1 For Addions"
echo "2 For Subtraction"
echo "3 For Multiplication"
echo "4 For Division"
echo "5 For Modulus"
echo "6 For exponentiation"
echo "7 For Floor division"
read opp
case $opp in
	1)echo "$(($a+$b))";;
	2)echo "$(($a-$b))";;
	3)echo "$(($a*$b))";;
	4)echo "$(($a/$b))";;
	5)echo "$(($a%$b))";;
	6)echo "$(($a**$b))";;
	7)echo "$(($a//$b))";;
	*)echo Invalid Input Try Again;;
esac
