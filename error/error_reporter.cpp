//
// Created by ggssh on 2021/10/10 0010.
//

#include "error_reporter.h"

using namespace nyar;

ErrorReporter::ErrorReporter(std::ostream &error_stream) :
        err(error_stream) {
}

void ErrorReporter::error(size_t line, size_t charPositionInline, const std::string &msg) {
    report(line, charPositionInline, msg, "Error");
}

void ErrorReporter::warn(size_t line, size_t charPositionInline, const std::string &msg) {
    report(line, charPositionInline, msg, "Warning");
}

void ErrorReporter::report(size_t line, size_t charPositionInline, const std::string &msg, const std::string &prefix) {
    err << prefix << "at position " << line << ":" << charPositionInline << " " << msg << std::endl;
}
