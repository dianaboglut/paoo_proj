#ifndef LOCK_H
#define LOCK_H

#include "Mutex.h"

class Lock {
public:
    explicit Lock(Mutex* pm)
        : mutexPtr(pm)
    {
        mutexPtr->lock();   // acquire resource
    }

    ~Lock() {
        mutexPtr->unlock(); // release resource
    }

    // Item 14: PROHIBIT copying
    Lock(const Lock&) = delete;
    Lock& operator=(const Lock&) = delete;

    // Copy makes no sense (two locks on one mutex = crash)
    Lock(Lock&&) = delete;
    Lock& operator=(Lock&&) = delete;

private:
    Mutex* mutexPtr;
};

#endif // LOCK_H