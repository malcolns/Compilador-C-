#!/bin/bash
bison -d calc.y
flex calc.l
gcc -c lex.yy.c 
g++ -o acc lex.yy.o calc.tab.c -ly -lfl

