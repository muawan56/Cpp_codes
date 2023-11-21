// Design a class for a book that includes the following features:

// Encapsulate book details (title, author, ISBN, number of pages)
// Implement methods to get and set the book details
// Implement a method to display the book's information

#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    string title, author, ISBN;
    int numOfPages;

public:
    // Default constructor
    Book() : title(""), author(""), numOfPages(0), ISBN("") {}
    Book(string title, string author, string ISBN, int numOfPages) : title(title), author(author), ISBN(ISBN), numOfPages(numOfPages) {}

    // GETTERS
    string getTitle() const
    {
        return title;
    }
    string getAuthor() const
    {
        return author;
    }
    string getISBN() const
    {
        return ISBN;
    }
    int getPages() const
    {
        return numOfPages;
    }

    // SETTERS
    void setTitle(const string &title)
    {
        if (title.empty())
        {
            throw invalid_argument("Title cannot be empty!");
        }
        this->title = title;
    }
    void setAuthor(const string &author)
    {
        if (author.empty())
        {
            throw invalid_argument("Author name cannot be empty!");
        }
        this->author = author;
    }
    void setISBN(const string &ISBN)
    {
        if (ISBN.length() != 17)
        {
            throw invalid_argument("Invalid length of ISBN.");
        }
        // if (!ISBN.starts_with("978-"))
        // {
        //     throw invalid_argument("Invalid argument entered.");
        // }
        this->ISBN = ISBN;
    }
    void setPages(const int &numOfPages)
    {
        if (numOfPages <= 0)
        {
            cerr << "Error: pages cannot be negative." << endl;
        }
        else
        {
            this->numOfPages = numOfPages;
        }
    }

    // Display information
    void display() const
    {
        cout << "Book tile: " << getTitle() << endl;
        cout << "Author name: " << getAuthor() << endl;
        cout << "ISBN of book: " << getISBN() << endl;
        cout << "Number of pages: " << getPages() << endl;
        cout << "-----------------------------" << endl;
    }
};

int main()
{

    Book b1;
    b1.setTitle("Upto the sky");
    b1.setAuthor("Piers Steel");
    b1.setISBN("978-0-123-45678-9");
    b1.setPages(679);
    b1.display();

    try
    {
        Book b2("", "", "122", 0);
        b2.display();
    }
    catch (const invalid_argument &e)
    {
        cout << "Error" << e.what() << endl;
    }

    return 0;
}