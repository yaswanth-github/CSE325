#!/bin/sh

a=1
b=2

y='expr $a+$b'

let 'z=$a+$b'

echo $y
echo $z


