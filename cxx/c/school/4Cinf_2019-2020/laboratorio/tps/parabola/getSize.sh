#!/bin/bash

TERMINAL=/dev/pts/0

COLUMNS=$(stty -a <"$TERMINAL" | grep -Po "(?<=columns )\d+")
ROWS=$(stty -a <"$TERMINAL" | grep -Po "(?<=rows )\d+")

echo $COLUMNS
echo $ROWS
