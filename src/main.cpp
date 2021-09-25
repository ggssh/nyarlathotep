#include <iostream>

#include "MyGrammarBaseListener.h"
#include "MyGrammarBaseVisitor.h"
#include "MyGrammarLexer.h"
#include "MyGrammarParser.h"
#include "antlr4-runtime.h"

using namespace std;
using namespace antlr4;

class TreeShapeListener : public MyGrammarBaseListener
{
  public:
//    void enterKey(ParserRuleContext *ctx) override
//    {
//        cout << "enter" << endl;
//    }
    void enterEveryRule(antlr4::ParserRuleContext *context) override {
        MyGrammarBaseListener::enterEveryRule(context);
        cout<<"enter"<<context->getText()<<endl;
    }
};

int main(int argc, const char* argv[]){
    ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    MyGrammarLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    MyGrammarParser parser(&tokens);

    tree::ParseTree *tree = parser.expr();
    TreeShapeListener listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
}