#ifndef WORKERS_H
#define WORKERS_H

#include "LoggerAsync.h"
#include "LoggerSync.h"
#include "SharedConfig.h"

void workerAsync(LoggerAsync& logger, int id);
void workerSync(std::shared_ptr<LoggerSync> logger, int id, SharedConfig config);

void demoAsyncVsSync();

void useUniqueLogger();
void useSharedLoggerAsync();

void demoFileHandleRAII();

#endif