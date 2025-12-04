#include "Workers.h"
#include "FileHandle.h"

#include <thread>
#include <chrono>
#include <future>
#include <iostream>

void workerAsync(LoggerAsync& logger, int id) {
    for (int i = 0; i < 10; ++i) {
        logger.log("Async thread " + std::to_string(id) + " iter " + std::to_string(i));
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void workerSync(std::shared_ptr<LoggerSync> logger, int id, SharedConfig config) {
    for (int i = 0; i < 10; ++i) {
        std::string msg = "[" + config.appName() +
            "][logLevel=" + std::to_string(config.logLevel()) +
            "] Sync thread " + std::to_string(id) +
            " iter " + std::to_string(i);

        logger->log(msg);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void demoAsyncVsSync() {
    std::cout << "\n=== Logger fara sincronizare ===\n";
    {
        LoggerAsync logger("unsync.log");
        std::thread t1(workerAsync, std::ref(logger), 1);
        std::thread t2(workerAsync, std::ref(logger), 2);
        t1.join();
        t2.join();
    }

    std::cout << "\n=== Logger cu sincronizare ===\n";
    {
        auto logger = std::make_shared<LoggerSync>("sync.log");
        SharedConfig config(1, "SyncDemo");

        std::thread t1(workerSync, logger, 1, config);
        std::thread t2(workerSync, logger, 2, config);
        std::thread t3(workerSync, logger, 3, config);

        t1.join();
        t2.join();
        t3.join();
    }
}

void useUniqueLogger() {
    std::cout << "\n=== Exemplu unique_ptr ===\n";

    std::unique_ptr<LoggerSync> logger(new LoggerSync("unique_logger.log"));

    logger->log("Mesaj 1 din main (unique_ptr)");
    logger->log("Mesaj 2 din main (unique_ptr)");

    std::unique_ptr<LoggerSync> logger2 = std::move(logger);
    logger2->log("Mesaj din logger2 dupa move");
}

void useSharedLoggerAsync() {
    std::cout << "\n=== Exemplu shared_ptr (async) ===\n";

    std::shared_ptr<LoggerSync> logger(new LoggerSync("shared_logger.log"));
    SharedConfig config(2, "DemoApp");

    auto f1 = std::async(std::launch::async, workerSync, logger, 1, config);
    auto f2 = std::async(std::launch::async, workerSync, logger, 2, config);

    config.setLogLevel(3);
    auto f3 = std::async(std::launch::async, workerSync, logger, 3, config);

    f1.get();
    f2.get();
    f3.get();
}

void demoFileHandleRAII() {
    std::cout << "\n=== Exemplu FileHandle RAII ===\n";

    FileHandle fh("filehandle_demo.txt", "w");
    std::fprintf(fh.get(), "Salut din FileHandle RAII!\n");

    FileHandle fh2 = std::move(fh);
    std::fprintf(fh2.get(), "Al doilea mesaj prin fh2.\n");
}