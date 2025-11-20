#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include "Book.hpp"

class Library{
    private:
        Book* books;
        std::size_t size;
        std::size_t capacity;
    public:
        Library(std::size_t cap = 10);
        Library(const Library& other);
        Library(Library&& other) noexcept;
        Library& operator=(const Library& other); // Copy assignment
        Library& operator=(Library&& other) noexcept; // Move assignment
        virtual ~Library();

        void transferBooksTo(Library& destination);
        void addBook(const Book& book);
        void removeBook(const std::string title);
        Book* findBook(const std::string title) const;
        int getBookCount() const;
        virtual void print() const;
};

#endif