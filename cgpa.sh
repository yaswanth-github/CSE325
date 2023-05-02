#!/bin/bash

echo "Enter 5 Subject Marks"

echo "Enter Subject 1 Marks"
read s1
echo "Enter Subject 2 Marks"
read s2
echo "Enter Subject 3 Marks"
read s3
echo "Enter Subject 4 Marks"
read s4
echo "Enter Subject 5 Marks"
read s5

marks=$(($s1+$s2+$s3+$s4+$s5))
echo $marks

per=$(echo "$marks / 500 * 100" | bc -l)
echo $per
cgpa=$(echo "$per / 9.5" | bc -l)
echo $cgpa
