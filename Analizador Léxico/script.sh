#!/bin/bash
flex lexycalanalyzer.l
gcc -o exec lex.yy.c -lfl
./exec

