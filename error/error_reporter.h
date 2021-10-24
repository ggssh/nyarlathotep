//
// Created by ggssh on 2021/10/10 0010.
//

#ifndef SILLYLANG_ERROR_REPORTER_H
#define SILLYLANG_ERROR_REPORTER_H

#include <iostream>

namespace silly {

    class ErrorReporter {
    public:
        ErrorReporter(std::ostream &error_stream);

        void error(size_t line, size_t charPositionInline, const std::string &msg);

        void warn(size_t line, size_t charPositionInline, const std::string &msg);

    protected:
        virtual void report(size_t line, size_t charPositionInline, const std::string &msg, const std::string &prefix);

    private:
        std::ostream &err;
    };
} // namespace silly
#endif // SILLYLANG_ERROR_REPORTER_H
