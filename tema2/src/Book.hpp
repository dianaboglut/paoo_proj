#include <iostream>
#include <string>

class Book{
    private:
        std::string title;
        std::string author;
        int publicationYear;
        int pages;
    public:
        Book(const std::string& t="", const std::string& a="", int year=0, int p=0):
            title(t), author(a), publicationYear(year), pages(p) {};
        // Book(const Book& other);
        // Book(Book&& other) noexcept;
        // Book& operator=(const Book& other); // Copy assignment
        // Book& operator=(Book&& other) noexcept; // Move assignment
        // ~Book();

        const std::string getTitle() const;
        const std::string getAuthor() const;
        int getPublicationYear() const;
        int getPages() const;
};