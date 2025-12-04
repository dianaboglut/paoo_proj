#include "FileHandle.h"

FileHandle::FileHandle(const std::string& path, const char* mode)
    : file_(std::fopen(path.c_str(), mode))
{
    if (!file_) {
        throw std::runtime_error("Nu pot deschide fisierul: " + path);
    }
}

FileHandle::~FileHandle() {
    if (file_) {
        std::fclose(file_);
    }
}

FileHandle::FileHandle(FileHandle&& other) noexcept
    : file_(other.file_)
{
    other.file_ = nullptr;
}

FileHandle& FileHandle::operator=(FileHandle&& other) noexcept {
    if (this != &other) {
        if (file_) {
            std::fclose(file_);
        }
        file_ = other.file_;
        other.file_ = nullptr;
    }
    return *this;
}

std::FILE* FileHandle::get() const {
    return file_;
}