#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string isbn;
    string title;
    string author;
    double price;
    bool available;
};

class Library {
private:
    Book books[100];
    int totalBooks = 0;

public:

    int findByISBN(string isbn) {
        for (int i = 0; i < totalBooks; i++) {
            if (books[i].isbn == isbn)
                return i;
        }
        return -1;
    }

    int findByTitle(string title) {
        for (int i = 0; i < totalBooks; i++) {
            if (books[i].title == title)
                return i;
        }
        return -1;
    }

    void addBook() {

        cin.ignore();

        cout << "Enter ISBN: ";
        getline(cin, books[totalBooks].isbn);

        cout << "Enter Title: ";
        getline(cin, books[totalBooks].title);

        cout << "Enter Author: ";
        getline(cin, books[totalBooks].author);

        cout << "Enter Price: ";
        cin >> books[totalBooks].price;

        books[totalBooks].available = true;

        totalBooks++;

        cout << "Book Added Successfully.\n";
    }

    void borrowBook() {

        string isbn;

        cin.ignore();

        cout << "Enter ISBN: ";
        getline(cin, isbn);

        int index = findByISBN(isbn);

        if (index == -1) {
            cout << "Book Not Found.\n";
            return;
        }

        if (!books[index].available) {
            cout << "Book Already Borrowed.\n";
            return;
        }

        books[index].available = false;

        cout << "Book Borrowed Successfully.\n";
    }

    void returnBook() {

        string isbn;

        cin.ignore();

        cout << "Enter ISBN: ";
        getline(cin, isbn);

        int index = findByISBN(isbn);

        if (index == -1) {
            cout << "Book Not Found.\n";
            return;
        }

        books[index].available = true;

        cout << "Book Returned Successfully.\n";
    }

    void searchByISBN() {

        string isbn;

        cin.ignore();

        cout << "Enter ISBN: ";
        getline(cin, isbn);

        int index = findByISBN(isbn);

        if (index == -1) {
            cout << "Book Not Found.\n";
            return;
        }

        cout << "\nISBN      : " << books[index].isbn << endl;
        cout << "Title     : " << books[index].title << endl;
        cout << "Author    : " << books[index].author << endl;
        cout << "Price     : " << books[index].price << endl;
        cout << "Available : ";

        if (books[index].available)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    void searchByTitle() {

        string title;

        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        int index = findByTitle(title);

        if (index == -1) {
            cout << "Book Not Found.\n";
            return;
        }

        cout << "\nISBN      : " << books[index].isbn << endl;
        cout << "Title     : " << books[index].title << endl;
        cout << "Author    : " << books[index].author << endl;
        cout << "Price     : " << books[index].price << endl;
        cout << "Available : ";

        if (books[index].available)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    void displayUnavailableBooks() {

        bool found = false;

        cout << "\nUnavailable Books\n";

        for (int i = 0; i < totalBooks; i++) {

            if (!books[i].available) {

                cout << "ISBN : " << books[i].isbn << endl;
                cout << "Title: " << books[i].title << endl;
                cout << "Author: " << books[i].author << endl;
                cout << endl;

                found = true;
            }
        }

        if (!found)
            cout << "No Borrowed Books.\n";
    }

    void totalLibraryValue() {

        double total = 0;

        for (int i = 0; i < totalBooks; i++)
            total += books[i].price;

        cout << "Total Library Value = " << total << endl;
    }
};

int main() {

    Library library;

    int choice;

    do {

        cout << "\n===== LIBRARY MENU =====\n";
        cout << "1. Add Book\n";
        cout << "2. Borrow Book\n";
        cout << "3. Return Book\n";
        cout << "4. Search by ISBN\n";
        cout << "5. Search by Title\n";
        cout << "6. Display Unavailable Books\n";
        cout << "7. Total Library Value\n";
        cout << "8. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            library.addBook();
            break;

        case 2:
            library.borrowBook();
            break;

        case 3:
            library.returnBook();
            break;

        case 4:
            library.searchByISBN();
            break;

        case 5:
            library.searchByTitle();
            break;

        case 6:
            library.displayUnavailableBooks();
            break;

        case 7:
            library.totalLibraryValue();
            break;

        case 8:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 8);

    return 0;
}
