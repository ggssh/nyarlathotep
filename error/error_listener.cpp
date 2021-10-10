//
// Created by ggssh on 2021/10/10 0010.
//

#include "error_listener.h"
using namespace silly;

ErrorListener::ErrorListener(ErrorReporter &e) :
    err(e), count(0) {
}
void ErrorListener::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol,
                                size_t line, size_t charPositionInline, const std::string &msg, std::exception_ptr e) {
    err.error(line, charPositionInline, msg);
    count++;
}
int ErrorListener::get_errors_count() {
    return count;
}
