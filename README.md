# nyarlathotep
![build status](https://github.com/ggssh/nyarlathotep/actions/workflows/cmake.yml/badge.svg)
## Environment
* ubuntu 20.04LTS
* antlr4-runtime-4.9
* openjdk 1.8.0_292
* gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
* cmake 3.16.3
* llvm 12
## Todo
- [x] 🎈能够生成正确的IR
- [ ] ⭐调用C的API(如printf方便测试输出)
- [ ] ⭐外部函数(自己实现的库函数)调用
- [ ] 代码重构
- [ ] 错误处理(词法,语法,语义)
- [ ] 添加JIT优化
- [ ] 自定义Pass优化
## Bugs to fix
* 函数内部定义的局部变量在cond中会出现cmp指令左右参数类型不同的错误