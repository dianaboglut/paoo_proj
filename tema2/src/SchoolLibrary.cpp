#include "SchoolLibrary.hpp"

SchoolLibrary::SchoolLibrary(std::string const& name, std::size_t cap)
    : Library(cap), schoolName(name) {}

SchoolLibrary::SchoolLibrary(const SchoolLibrary& other)
    : Library(other), schoolName(other.schoolName) {
        std::cout << "SchoolLibrary Copy Constructor called for " << schoolName << std::endl;
}

SchoolLibrary& SchoolLibrary::operator=(const SchoolLibrary& other) {
    if(this == &other){
        return *this;
    }

    Library::operator=(other);
    schoolName = other.schoolName;

    return *this;
}

void SchoolLibrary::print() const {
    std::cout << "\n=== SCHOOL LIBRARY INFO ===" << std::endl;
    std::cout << "School: " << schoolName  << std::endl;
    
    Library::print();
}