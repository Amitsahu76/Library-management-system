#include <iostream>
#include <string>
#include <list>
#include <unordered_map>

using namespace std;

struct Book {
    int id;
    string title;
    string author;
};

class Library {
    list<Book> books;
    unordered_map<int, Book> bookMap;

public:
    void addBook(int id, string title, string author) {
        Book b = {id, title, author};
        books.push_back(b);
        bookMap[id] = b;
        cout << "Book added: " << title << endl;
    }

    void removeBook(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == id) {
                books.erase(it);
                bookMap.erase(id);
                cout << "Book removed." << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void searchBook(int id) {
        if (bookMap.find(id) != bookMap.end()) {
            Book b = bookMap[id];
            cout << "Book Found: " << b.title << " by " << b.author << endl;
        } else {
            cout << "Book not found." << endl;
        }
    }

    void displayBooks() {
        cout << "\nBooks in Library:" << endl;
        for (auto &b : books) {
            cout << "ID: " << b.id << ", Title: " << b.title << ", Author: " << b.author << endl;
        }
    }
};

int main() {
    Library lib;
    int choice, id;
    string title, author;

    do {
        cout << "\n1. Add Book\n2. Remove Book\n3. Search Book\n4. Display Books\n0. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter ID, Title, Author: ";
                cin >> id;
                cin.ignore();
                getline(cin, title);
                getline(cin, author);
                lib.addBook(id, title, author);
                break;
            case 2:
                cout << "Enter ID to remove: ";
                cin >> id;
                lib.removeBook(id);
                break;
            case 3:
                cout << "Enter ID to search: ";
                cin >> id;
                lib.searchBook(id);
                break;
            case 4:
                lib.displayBooks();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}

