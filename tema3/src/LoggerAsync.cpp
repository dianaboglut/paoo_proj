#include "LoggerAsync.h"
#include <stdexcept>

LoggerAsync::LoggerAsync(const std::string& filename)
    : file_(filename, std::ios::app)
{
    if (!file_) {
        throw std::runtime_error("Nu pot deschide fisierul: " + filename);
    }
}

void LoggerAsync::log(const std::string& msg) {
    file_ << msg << '\n';
    file_.flush();
}