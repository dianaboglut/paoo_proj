#ifndef FILEHANDLE_H
#define FILEHANDLE_H

#include <string>
#include <cstdio>
#include <stdexcept>

class FileHandle {
public:
    explicit FileHandle(const std::string& path, const char* mode);
    ~FileHandle();

    FileHandle(const FileHandle&) = delete;
    FileHandle& operator=(const FileHandle&) = delete;

    FileHandle(FileHandle&& other) noexcept;
    FileHandle& operator=(FileHandle&& other) noexcept;

    std::FILE* get() const;

private:
    std::FILE* file_;
};

#endif // FILEHANDLE_H