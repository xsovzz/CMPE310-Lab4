# Lab 4 – Array Sum (x86-64 Assembly)

## Description
This program reads integers from a file into an array using C.
The array is passed to an assembly function which sums the values
and returns the result.

File format:
- First line: number of integers (N)
- Next N lines: one integer per line

## Build
make

## Complie
gcc -Wall -Wextra -g main.c sum_array.s -o lab4

## Run
./lab4 data.txt

## Output using given data.txt
Sum = 5559
