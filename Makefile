.PHONY: all build test clean

all: build test clean

# 编译构建
build:
	flex src/scanner.l
	gcc -o lexical lex.yy.c -lfl

# 样例测试
test:
	@echo test1.pl0
	@./lexical < test/test1.pl0
# @echo test2.pl0
# @./lexical < test/test2.pl0
# @echo test3.pl0
# @./lexical < test/test3.pl0

# 清除生成的文件
clean:
	@rm -rf lex.yy.c lexical