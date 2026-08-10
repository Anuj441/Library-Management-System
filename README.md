# Library Management System

A console-based Library Management System developed in C++ using object-oriented programming.

## Features

- Add books
- Add library members
- Issue books to members
- Return books
- Search books by title
- Search books by author
- Display all books and their availability
- Display all registered members
- Prevent duplicate book/member IDs
- Prevent issuing an already issued book
- Validate book and member IDs during issue operations

## OOP Concepts Used

- Classes and objects
- Encapsulation
- Constructors
- Member functions
- Vectors
- Pointers
- Private helper functions

## Requirements

- C++ compiler supporting C++11 or later
- VS Code, Code::Blocks, Dev-C++, or any C++ IDE

## Compile and Run

### Windows with g++

```bash
g++ main.cpp -o library
library
```

### Linux/macOS

```bash
g++ main.cpp -o library
./library
```

## Example Flow

1. Add a book with ID, title, and author.
2. Add a member with ID and name.
3. Issue the book using the book ID and member ID.
4. Search for the book by title or author.
5. Return the book.
6. Display the books to verify its availability.
