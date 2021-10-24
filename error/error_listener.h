//
// Created by ggssh on 2021/10/10 0010.
//

#ifndef SILLYLANG_ERROR_LISTENER_H
#define SILLYLANG_ERROR_LISTENER_H

#include "BaseErrorListener.h"
#include "error_reporter.h"

namespace silly {
    class ErrorListener : public antlr4::BaseErrorListener {
    public:
        ErrorListener(ErrorReporter &e);

        virtual void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                                 size_t charPositionInline, const std::string &msg, std::exception_ptr e) override;

        int get_errors_count();

    private:
        ErrorReporter &err;
        int count;
    };
} // namespace silly

#endif // SILLYLANG_ERROR_LISTENER_H
