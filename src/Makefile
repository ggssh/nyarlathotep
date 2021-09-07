all:
	flex scanner.l
	gcc lex.yy.c -lfl
	./a.out < ../test/test1.pl0