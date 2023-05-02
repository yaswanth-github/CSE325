#!/bin/bash

echo Enter Your Age:
read age
echo Enter Your Marks in Percentage:
read marks
echo Enter Your Attandance:
read att

if [ $age -ge 22 ] && [ $marks -ge 70 ] && [ $att -ge 75 ]
then
	echo "Your eligible to appear in the placement drive"
else
	echo "Sorry. better luck next time."
fi

