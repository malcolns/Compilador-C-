!#/bin/bash
bison -d us.y
flex us.l
gcc -o steemit us.tab.c lex.yy.c 
rm lex.yy.c us.tab.c
./steemit input.txt