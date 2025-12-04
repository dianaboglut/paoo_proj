#include <iostream>
#include "Workers.h"

int main() {
    try {
        demoFileHandleRAII();
        demoAsyncVsSync();
        useUniqueLogger();
        useSharedLoggerAsync();
    }
    catch (const std::exception& ex) {
        std::cerr << "Exceptie: " << ex.what() << '\n';
    }
}