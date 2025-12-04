#include "LoggerSync.h"
#include <stdexcept>
#include <mutex>

LoggerSync::LoggerSync(const std::string& filename)
    : file_(filename, std::ios::app)
{
    if (!file_) {
        throw std::runtime_error("Nu pot deschide fisierul: " + filename);
    }
}

void LoggerSync::log(const std::string& msg) {
    Lock lock(&mutex_);
    file_ << msg << '\n';
    file_.flush();
}