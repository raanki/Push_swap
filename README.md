
<p>
  <img src="Score_Push_swap.png" alt="Score Push_swap 86/100" align="left">
# Push_swap

This project asks you to sort data on a stack,
with a limited instruction set, in as few moves as possible.
To succeed, you will have to manipulate different sorting algorithms
To succeed, you will have to manipulate different sorting algorithms and choose the most appropriate solution(s) for an optimised sorting of the data.
</p>

## Introduction
The Push_swap project is a simple and efficient algo project: you have to sort. You have a set of
a set of integers, two stacks, and a set of instructions to manipulate the stacks.
manipulate the stacks.

Your goal? Write two programs in C:

- One called checker which takes integers as parameters and reads
instructions on the standard input. Once these instructions are read, checker executes them
then displays OK if the integers are sorted, or KO otherwise.
- A second one called push_swap which calculates and displays on the standard output the smallest
smallest program in the language of the Push_swap instructions that sorts the integers
passed in parameter.

## Rules of the game
The game consists of 2 stacks named a and b.
- At the start:
  * a contains an arbitrary number of positive or negative integers, without duplicates.
  * b is empty
- The aim of the game is to sort a in ascending order.
- To do this, we only have the following operations:

   __sa__ : swap a - swaps the first 2 elements at the top of the stack a. Does not
nothing if there is only one or none.  
   __sb__: swap b - swaps the first 2 elements on top of the stack b. Does not
nothing if there is only one or none.  
   __ss__: sa and sb at the same time.  
   __pa__: push a - takes the first element at the top of b and puts it on a. Does not
nothing if b is empty.  
   __pb__: push b - takes the first element on top of a and sets it to b. Does not
nothing if a is empty.  
   __ra__: rotate a - shifts all elements of the stack a up one position.
The first element becomes the last.  
   __rb__: rotate b - shifts all elements of the stack b up one position.
The first element becomes the last.  
   __rr__: ra and rb at the same time.  
   __rra__: reverse rotate a - shifts all elements of the stack down one position a. The first element becomes the last.
the stack a. The last element becomes the first.  
   __rrb__: reverse rotate b - shifts all elements of the stack down one position
the stack b. The last element becomes the first.  
   __rrr__: rra and rrb at the same time.  
   
## The *checker* program
The *checker* program takes as parameter the stack as a list of integers.
The first parameter is at the top of the stack (so be careful of the order).
Checker must then wait to read instructions from the standard input, each instruction followed by an
instruction followed by an '\n'. Once all instructions have been read, the checker will
execute these instructions on the integer stack passed as parameters.
```
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 one 0
Error
$>
```
## The *push_swap* program
The *push_swap* program takes as parameter the
a-stack as a list of integers. The first parameter is at the top
of the stack (so be careful of the order). If no parameter is passed, push_swap
ends immediately and displays nothing.  
The program must display the program composed of the smallest possible sequence of instructions
that sorts the stack a, with the smallest number on top.
```
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>
```

## Download
```
git clone git@github.com:raanki/Push_swap.git ; cd push_swap ; make
```
## Use
```
$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
9
$>
```
