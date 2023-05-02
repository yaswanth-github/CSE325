#!/bin/sh

marks=345

per=$(((marks * 100) / 500))
cgpa=$((($per / (95 / 10))))
echo $per
echo $cgpa

