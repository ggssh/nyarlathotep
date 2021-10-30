~~~ bash
配置java和antlr
export CLASSPATH=".:/usr/local/lib/antlr-4.9-complete.jar:$CLASSPATH"
alias antlr4='java -Xmx500M -cp "/usr/local/lib/antlr-4.9-complete.jar:$CLASSPATH" org.antlr.v4.Tool'
alias grun='java -Xmx500M -cp "/usr/local/lib/antlr-4.9-complete.jar:$CLASSPATH" org.antlr.v4.gui.TestRig'
~~~
~~~ bash
在grammar目录下使用如下命令
antlr4 -Dlanguage=Cpp Nyar.g4 -visitor -o ../dist
~~~
~~~ python
python3 ./asdl_cpp.py -h AST.h -c AST.cpp AST.asdl
~~~