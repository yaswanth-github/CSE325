#!/bin/sh
echo "Enter What Table You Need"
read t

for i in {1..20}
do
	echo "$t X $i = $(($t*$i))"
done
 
