#ifndef SHAREDCONFIG_H
#define SHAREDCONFIG_H

#include <memory>
#include <string>

struct ConfigData {
    int logLevel;
    std::string appName;
};

class SharedConfig {
public:
    SharedConfig(int logLevel, std::string appName);

    int logLevel() const;
    std::string appName() const;

    void setLogLevel(int level);

private:
    std::shared_ptr<ConfigData> data_;
};

#endif