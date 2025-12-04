#ifndef MUTEX_H
#define MUTEX_H

#include <mutex>

class Mutex {
public:
    void lock()   { m.lock(); }
    void unlock() { m.unlock(); }

private:
    std::mutex m;
};

#endif