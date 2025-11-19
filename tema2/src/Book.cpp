#include "Book.hpp"

const std::string Book::getTitle() const {
    return title;
}

const std::string Book::getAuthor() const {
    return author;
}

int Book::getPublicationYear() const {
    return publicationYear;
}

int Book::getPages() const {
    return pages;
}