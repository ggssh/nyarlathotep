default:build check
build:
# bison -d src/parsing.y
	flex -o scanner.c src/scanner.l
	gcc -o scanner scanner.c -lfl
check:
# ./lexical < test/testcase.pl0
	./scanner < test/test2.pl0
# ./scanner < test/test2.pl0
# ./scanner < test/test3.pl0
# ./scanner < test/test4.pl0

clean:
	rm scanner*
.PHONY:default build check clean
