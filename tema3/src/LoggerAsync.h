#ifndef LOGGERASYNC_H
#define LOGGERASYNC_H

#include <fstream>
#include <string>

class LoggerAsync {
public:
    explicit LoggerAsync(const std::string& filename);

    LoggerAsync(const LoggerAsync&) = delete;
    LoggerAsync& operator=(const LoggerAsync&) = delete;

    void log(const std::string& msg);

private:
    std::ofstream file_;
};

#endif