#!/bin/bash

# function to calculate CGPA
calculate_cgpa() {
  sum=0
  for grade in "$@"; do
    case $grade in
      A) sum=$((sum + 4)) ;;
      B+) sum=$((sum + 3.5)) ;;
      B) sum=$((sum + 3)) ;;
      C+) sum=$((sum + 2.5)) ;;
      C) sum=$((sum + 2)) ;;
      D+) sum=$((sum + 1.5)) ;;
      D) sum=$((sum + 1)) ;;
      F) sum=$((sum + 0)) ;;
      *) echo "Invalid grade. Only A, B+, B, C+, C, D+, D, F are allowed."
         return 1
         ;;
    esac
  done

  cgpa=$(echo "$sum / $#" | bc -l)
  echo "CGPA: $cgpa"
}

# prompt user to enter grades
echo "Enter your grades (A, B+, B, C+, C, D+, D, F) separated by space: "
read -a grades

# call the function to calculate CGPA
calculate_cgpa "${grades[@]}"

