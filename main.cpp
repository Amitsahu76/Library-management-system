#include <bits/stdc++.h>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
};

class Library {
private:
    vector<Book> books;
public:
    void addBook(int id, string title, string author) {
        books.push_back({id, title, author, false});
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        cout << "\nLibrary Books:\n";
        for (auto &b : books) {
            cout << "ID: " << b.id << " | Title: " << b.title << " | Author: " << b.author 
                 << " | Status: " << (b.isIssued ? "Issued" : "Available") << "\n";
        }
    }

    void issueBook(int id) {
        for (auto &b : books) {
            if (b.id == id) {
                if (!b.isIssued) {
                    b.isIssued = true;
                    cout << "Book issued successfully!\n";
                } else {
                    cout << "Book already issued!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }

    void returnBook(int id) {
        for (auto &b : books) {
            if (b.id == id) {
                if (b.isIssued) {
                    b.isIssued = false;
                    cout << "Book returned successfully!\n";
                } else {
                    cout << "Book was not issued!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }
};

int main() {
    Library lib;
    int choice;
    do {
        cout << "\n--- Library Management System ---\n";
        cout << "1. Add Book\n2. Display Books\n3. Issue Book\n4. Return Book\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string title, author;
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Book Author: ";
            getline(cin, author);
            lib.addBook(id, title, author);
        }
        else if (choice == 2) {
            lib.displayBooks();
        }
        else if (choice == 3) {
            int id;
            cout << "Enter Book ID to issue: ";
            cin >> id;
            lib.issueBook(id);
        }
        else if (choice == 4) {
            int id;
            cout << "Enter Book ID to return: ";
            cin >> id;
            lib.returnBook(id);
        }
        else if (choice == 5) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
