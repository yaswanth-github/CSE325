#!/bin/sh

echo "Enter Your Option:"
echo "a-To Create a New Text File"
echo "b-To implement if-else loop for 75% attendence"
echo "c-To Exit From the Program"

read option

case $option in
	a)echo Enter the filename:
            read fn
	    touch $fn.txt;;
	b)echo "Enter Your Atttendance Percantage:"
	read att
	if [ $att -ge 75 ]
	 then
		echo "Your Attendance is greater than 75%"
	else
		echo "Your Attendace is Less than 75%"
	fi;;
	c)exit;;
	*)echo "Sorry Invalid Input!";;
esac
