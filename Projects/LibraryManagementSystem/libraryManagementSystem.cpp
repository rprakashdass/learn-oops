#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

/* later for robustness of the system
static int ID_FOR_AUTHOR = 1;

class Author{
    private:
    int authorID;
    std::string authorName;
    std::vector<Book> books;
    public:
    Author() : authorID(ID_FOR_AUTHOR){}
    Author(std::string name) : authorID(ID_FOR_AUTHOR), authorName(name) {}
    Author(std::vector<Book> book) {
        books.emplace_back(book);
    }
};
*/

/*
Book:

Attributes: bookID, title, author, isIssued.
Methods: issueBook(), returnBook() - {not needed as library class is managing}.

Member:

Attributes: memberID, name, booksIssued.
Methods: issueBook(), returnBook() - {not needed as library class is managing}.

Library:

Attributes: books (list of books), members (list of members).
Methods: addBook(), removeBook(), searchBook(), issueBook(), returnBook().

        Add methods to:
        Add/remove books.
        Add members.
        Search for books by ID.
        Issue/return books.
*/

// static variables
static int ID_FOR_BOOK = 111;
static int ID_FOR_MEMBER = 111;

class Book{
private:
    int bookID;
    std::string title;
    std::string author;
    bool isIssued = false;
public:
    Book(std::string title) : bookID(ID_FOR_BOOK++), title(title), author("Unknown") {}
    Book( std::string title, std::string author)
    : bookID(ID_FOR_BOOK++), title(title), author(author) {}
    int getBookID() const {return this->bookID;}
    std::string getBookName() const {return this->title;}
    void issueBook(){isIssued = true;}
    void returnBook(){isIssued = false;}
    void showDetails() const {
        std::cout << "Book ID : " << this->bookID << std::endl;
        std::cout << "Book Title : " << this->title << std::endl;
        std::cout << "Book Author : " << this->author << std::endl;
        std::cout << "Book isAvailable : " << ((!this->isIssued) ? "True" : "False") << std::endl;
    }
    ~Book() {
        std::cout << "Book " << title << " destroyed." << std::endl;
    }
};


class Member{
private:
    int memberID;
    std::string name;
    std::vector<Book*> books;
public:
    Member(std::string name) : memberID(ID_FOR_MEMBER++) ,name(name) {}
    void issueBook(Book* book){
        book->issueBook();
        books.emplace_back(book);
    }
    std::string getName() const {
        return this->name;
    }
    void returnBook(Book* book){
        auto it = find(books.begin(), books.end(), book);
        if(it == books.end()) {
            std::cout << "Book not found!" << std::endl;
            return;
        }
        books.erase(it);
        book->returnBook();
        std::cout << "Book successfully returned by user!" << std::endl;
    }
    void showDetails() const {
        std::cout << "Member ID : " << this->memberID << std::endl;
        std::cout << "Member Title : " << this->name << std::endl;
        std::cout << "Books Issued : ";
        if(books.empty()) std::cout << 0;
        std::cout << std::endl;
        for(Book* book : books){
            book->showDetails();
        }
    }
    ~Member(){
        std::cout << "Member " << name << " destroyed." << std::endl;
    }
};

class Library{
private:
    std::vector<Book*> books;
    std::vector<Member*> members;
    std::vector<Book*>::iterator findBook(Book* book){
        return find(books.begin(), books.end(), book);
    }
public:
    void addBook(Book* book){
        if(findBook(book) != books.end()){
            std::cout << "Book allready Added!" << std::endl;
            return;
        }
        books.emplace_back(book);
        std::cout << "Book Successfully added!" << std::endl;
    }
    void removeBook(std::string bookName){
        auto it = findBook(searchBookByName(bookName));
        if(it != books.end()){
            books.erase(it);
        } else {
            std::cout << EXIT_FAILURE << std::endl;
        }
    }
    Book* searchBookById(int id) const{
        for(Book* book: books){
            if(book->getBookID() == id) {
                std::cout << "found the book" << std::endl;
                book->showDetails();
                return book;
            }
        }
        return nullptr;
    }
    Book* searchBookByName(std::string name) const{
        for(Book* book: books){
            if(book->getBookName() == name) {
                std::cout << "found the book" << std::endl;
                book->showDetails();
                return book;
            }
        }
        return nullptr;
    }
    void addMember(Member* member){
        auto it = find(members.begin(), members.end(), member);
        if(it != members.end()){
            std::cout << "Member allready Added!" << std::endl;
            return;
        }
        members.emplace_back(member);
        std::cout << "Member Successfully added!" << std::endl;
    }
    void issueBook(Member* member, Book* book){
        auto it = find(members.begin(), members.end(), member);
        if(it == members.end()){
            std::cout << "Member not found!" << std::endl;
            return;
        }
        auto bookIterator = find(books.begin(), books.end(), book);
        if(bookIterator == books.end()){
            std::cout << "Book not found!" << std::endl;
            return;
        }
        member->issueBook(book);
        std::cout << "Book Successfully issued to the member!" << std::endl;
    }
    void removeBookById(int id) {
        for(auto it = books.begin();it != books.end();){
            if((*it)->getBookID() == id){
                delete *it;
                it = books.erase(it);
                std::cout << "Book has been removed" << std::endl;
                return;
            } else {
                ++it;
            }
        }
        std::cout << "Book not found!" << std::endl;
    }
    void returnBook(Member* member, Book* book) const {
        member->returnBook(book);
        book->returnBook();
    }
    void showBooks() const {
        std::cout << "Books in Library " << std::endl;
        for(Book* book : books){
            book->showDetails();
        }
    }
    ~Library(){
        for(Book* book: books){
            delete book;
        }
        for(Member* member: members){
            delete member;
        }
        std::cout << "library destructor called" << std::endl;
    }
};

int main(){
    Book* book1 = new Book("Atomic Habits");
    Book* book2 = new Book("Richest Man in babylon", "doe");
    Book* book3 = new Book("Zero to One", "Peter  Theil");
    book1->showDetails();
    book2->showDetails();
    std::cout << std::endl;

    Member* member1 = new Member("Prakash Dass R");
    member1->showDetails();

    Member* member2 = new Member("Gowtham G");
    member2->showDetails();
    std::cout << std::endl;

    Library* library = new Library;
    library->addBook(book1);
    library->addBook(book2);
    library->addBook(book3);
    std::cout << std::endl;
    library->showBooks();
    std::cout << std::endl;

    library->addMember(member1);
    library->addMember(member2);
    std::cout << std::endl;

    library->removeBookById(111);
    library->removeBookById(303);
    std::cout << std::endl;
    library->searchBookById(300);
    library->searchBookByName("Atomic Habits");
    std::cout << std::endl;
    library->showBooks();
    std::cout << std::endl;

    library->issueBook(member2, book1);
    std::cout << std::endl;
    library->issueBook(member2, book2);
    std::cout << std::endl;
    member2->showDetails();

    member2->returnBook(book2);

    std::cout << std::endl;
    library->showBooks();
    std::cout << std::endl;

    delete library;

}