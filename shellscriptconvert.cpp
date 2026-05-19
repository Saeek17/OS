#!/bin/bash

echo "1. Decimal to Binary"
echo "2. Binary to Decimal"

echo "Enter your choice:"
read ch

# Decimal to Binary

if [ $ch -eq 1 ]
then
    echo "Enter Decimal Number:"
    read n

    bin=""

    while [ $n -gt 0 ]
    do
        rem=$((n % 2))
        bin="$rem$bin"
        n=$((n / 2))
    done

    echo "Binary Number is: $bin"

# Binary to Decimal

elif [ $ch -eq 2 ]
then
    echo "Enter Binary Number:"
    read bin

    dec=0
    base=1

    while [ $bin -gt 0 ]
    do
        rem=$((bin % 10))
        dec=$((dec + rem * base))
        base=$((base * 2))
        bin=$((bin / 10))
    done

    echo "Decimal Number is: $dec"

else
    echo "Invalid Choice"

fi
