#!/bin/sh

echo "Enter Your Income"
read income

if [ $income -ge 700000 ]
then
	tax=$((($income * 30) / 100))
	echo "The Amount of Tax you shoud pay is $tax"
else
	echo "No Need to pay Income Tax"
fi

