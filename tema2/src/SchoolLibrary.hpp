#include "Library.hpp"
#include <iostream>

class SchoolLibrary : public Library {
    private:
        std::string schoolName;
    public:
        SchoolLibrary(const std::string& name, std::size_t cap = 10);

        SchoolLibrary(const SchoolLibrary& other);
        SchoolLibrary& operator=(const SchoolLibrary& other);

        void print() const override;
};