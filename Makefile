Objectso = UpdateLineParams.o main.o IOfuncs.o Parser.o FindMatch.o Expression.o

CFLAGS_mygrep= -std=c99 -Wall -Wextra -g -o
CFLAGS_rest= -c -std=c99 -g

.PHONY: all clean test

all: my_grep

my_grep: UpdateLineParams.o main.o IOfuncs.o Parser.o FindMatch.o Expression.o
	gcc $(Objectso) $(CFLAGS_mygrep) my_grep

test: my_grep
	./test.sh

main.o: main.c
	gcc $(CFLAGS_rest) main.c
  
UpdateLineParams.o: UpdateLineParams.c UpdateLineParams.h
	gcc $(CFLAGS_rest) UpdateLineParams.c
 
IOfuncs.o: IOfuncs.c IOfuncs.h
	gcc $(CFLAGS_rest) IOfuncs.c
  
Parser.o: Parser.c Parser.h
	gcc $(CFLAGS_rest) Parser.c 
  
FindMatch.o: FindMatch.c FindMatch.h
	gcc $(CFLAGS_rest) FindMatch.c

Expression.o: Expression.c Expression.h
	gcc $(CFLAGS_rest) Expression.c

clean:
	rm *.o my_grep


