#ifndef LOGGERSYNC_H
#define LOGGERSYNC_H


#include <fstream>
#include <string>
#include "Mutex.h"
#include "Lock.h"

class LoggerSync {
public:
    explicit LoggerSync(const std::string& filename);

    LoggerSync(const LoggerSync&) = delete;
    LoggerSync& operator=(const LoggerSync&) = delete;

    void log(const std::string& msg);

private:
    std::ofstream file_;
    Mutex mutex_;
};

#endif