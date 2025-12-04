#include "SharedConfig.h"

SharedConfig::SharedConfig(int logLevel, std::string appName)
    : data_(std::shared_ptr<ConfigData>(
        new ConfigData{ logLevel, std::move(appName) }
      ))
{}

int SharedConfig::logLevel() const {
    return data_->logLevel;
}

std::string SharedConfig::appName() const {
    return data_->appName;
}

void SharedConfig::setLogLevel(int level) {
    data_->logLevel = level;
}