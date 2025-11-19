#include "Library.hpp"
#include <iostream>
#include <cstring>

Library::Library(std::size_t cap)
    : books(new Book[cap]) ,size(0), capacity(cap) {}

Library::~Library() {
    delete[] books;
}

// Item 12: Copiază toate părțile obiectului (deep copy)
Library::Library(const Library& other)
    : books(new Book[other.capacity]), size(other.size), capacity(other.capacity) {
        for(std::size_t i = 0; i < size; i++){
            books[i] = other.books[i];
        }

    }

Library& Library::operator=(const Library& other) {
    // Item 11: Self-assignment check
    if(this == &other){
        return *this;
    }

    size = other.size;
    capacity = other.capacity;

    delete[] books;

    books = new Book[capacity];
    for(std::size_t i = 0; i < size; i++){
        books[i] = other.books[i];
    }

    // Item 10: Return *this to allow chained assignments
    return *this;
}

void Library::addBook(const Book& book){
    if(size >= capacity){
        // or i could resize the array here
        std::cerr << "Library is full. Cannot add more books." << std::endl;
        return;
    }
    books[size++] = book;
}

void Library::removeBook(const std::string title){
    for(std::size_t i = 0; i < size; i++){
        if(books[i].getTitle() == title){
            // Shift books to the left
            for(std::size_t j = i; j < size - 1; j++){
                books[j] = books[j + 1];
            }
            size--;
            return;
        }
    }
    std::cerr << "Book with title \"" << title << "\" not found." << std::endl;
}

void Library::print() const {
    std::cout << size << " books:" << std::endl;
    for(std::size_t i = 0; i < size; i++){
        std::cout << "Title: " << books[i].getTitle() << ", "
                << "Author: " << books[i].getAuthor() << ", "
                << "Year: " << books[i].getPublicationYear() << ", "
                << "Pages: " << books[i].getPages()
                << std::endl;
    }
    std::cout << std::endl;
}