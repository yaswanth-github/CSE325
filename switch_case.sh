#!/etc/bash

echo "Enter Your Option"
echo "1-For Current Date and Time"
echo "2-For Current Path"
echo "3-FOr Current Dir"
read a

case "$a" in
	1)date;;
	2)pwd;;
	3)ls;;
	*)echo "Invalid Input!";;
esac
