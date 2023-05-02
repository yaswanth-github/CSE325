#!/bin/sh

echo Enter Your Roll No.
read roll
sub=0
mooc=5
list="English Computer Science S.St. Hindi Sanskrit"

if [ $roll -le 34 ]
then
	while [ $sub -le $mooc ]
	do
		for i in $list
		do
			echo Your $i is $sub
			let sub++
		done
	done
else
	echo U do Not belong here..!
fi
