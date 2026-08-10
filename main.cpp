#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;
    int issuedTo;

    Book(int id, string title, string author)
        : id(id), title(title), author(author), issued(false), issuedTo(-1) {}
};

class Member {
public:
    int id;
    string name;

    Member(int id, string name) : id(id), name(name) {}
};

class Library {
private:
    vector<Book> books;
    vector<Member> members;

    Book* findBook(int id) {
        for (auto& book : books)
            if (book.id == id)
                return &book;
        return nullptr;
    }

    Member* findMember(int id) {
        for (auto& member : members)
            if (member.id == id)
                return &member;
        return nullptr;
    }

public:
    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter book ID: ";
        cin >> id;

        if (findBook(id)) {
            cout << "Book ID already exists.\n";
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);

        books.emplace_back(id, title, author);
        cout << "Book added successfully.\n";
    }

    void addMember() {
        int id;
        string name;

        cout << "\nEnter member ID: ";
        cin >> id;

        if (findMember(id)) {
            cout << "Member ID already exists.\n";
            return;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter member name: ";
        getline(cin, name);

        members.emplace_back(id, name);
        cout << "Member added successfully.\n";
    }

    void issueBook() {
        int bookId, memberId;

        cout << "\nEnter book ID: ";
        cin >> bookId;
        cout << "Enter member ID: ";
        cin >> memberId;

        Book* book = findBook(bookId);
        Member* member = findMember(memberId);

        if (!book) {
            cout << "Book not found.\n";
            return;
        }

        if (!member) {
            cout << "Member not found.\n";
            return;
        }

        if (book->issued) {
            cout << "Book is already issued.\n";
            return;
        }

        book->issued = true;
        book->issuedTo = memberId;
        cout << "Book issued successfully to " << member->name << ".\n";
    }

    void returnBook() {
        int bookId;
        cout << "\nEnter book ID: ";
        cin >> bookId;

        Book* book = findBook(bookId);

        if (!book) {
            cout << "Book not found.\n";
            return;
        }

        if (!book->issued) {
            cout << "Book is not currently issued.\n";
            return;
        }

        book->issued = false;
        book->issuedTo = -1;
        cout << "Book returned successfully.\n";
    }

    void searchBook() {
        int choice;
        string query;
        bool found = false;

        cout << "\n1. Search by title\n";
        cout << "2. Search by author\n";
        cout << "Enter choice: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter search text: ";
        getline(cin, query);

        string lowerQuery = query;
        transform(lowerQuery.begin(), lowerQuery.end(), lowerQuery.begin(), ::tolower);

        for (const auto& book : books) {
            string field = (choice == 1) ? book.title : book.author;
            string lowerField = field;
            transform(lowerField.begin(), lowerField.end(), lowerField.begin(), ::tolower);

            if (lowerField.find(lowerQuery) != string::npos) {
                cout << "\nID: " << book.id
                     << "\nTitle: " << book.title
                     << "\nAuthor: " << book.author
                     << "\nStatus: " << (book.issued ? "Issued" : "Available") << "\n";
                found = true;
            }
        }

        if (!found)
            cout << "No matching book found.\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "\nNo books available.\n";
            return;
        }

        cout << "\n----- All Books -----\n";
        for (const auto& book : books) {
            cout << "ID: " << book.id
                 << " | Title: " << book.title
                 << " | Author: " << book.author
                 << " | Status: " << (book.issued ? "Issued" : "Available");

            if (book.issued)
                cout << " | Member ID: " << book.issuedTo;

            cout << '\n';
        }
    }

    void displayMembers() {
        if (members.empty()) {
            cout << "\nNo members registered.\n";
            return;
        }

        cout << "\n----- All Members -----\n";
        for (const auto& member : members)
            cout << "ID: " << member.id << " | Name: " << member.name << '\n';
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\n========== Library Management System ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Add Member\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search Book\n";
        cout << "6. Display All Books\n";
        cout << "7. Display All Members\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: library.addBook(); break;
            case 2: library.addMember(); break;
            case 3: library.issueBook(); break;
            case 4: library.returnBook(); break;
            case 5: library.searchBook(); break;
            case 6: library.displayBooks(); break;
            case 7: library.displayMembers(); break;
            case 0: cout << "Exiting program. Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
