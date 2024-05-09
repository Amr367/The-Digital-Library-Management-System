#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to represent a book
struct Book {
    int id;
    string name;
    double price;
    int quantity;
};

// Function to search for a book by ID
Book search_book(const vector<Book>& library, int bookId) {
    for (const Book& book : library) {
        if (book.id == bookId) {
            return book;
        }
    }
    // Return a default book with id -1 if not found
    return { -1, "", 0.0, 0 };
}

// Function to create a new user account
void create_account(string username, string password, string email, string validationPassword) {
    // Implement account creation logic here
    cout << "Account created successfully!" << endl;
}

// Function to log in a user
bool login(string username, string password) {
    // Implement login logic here
    // Return true if login is successful, false otherwise
    return true;
}

// Function to add a book to the library
void add_book(vector<Book>& library, int id, string name, double price, int quantity) {
    // Implement book addition logic here
    library.push_back({ id, name, price, quantity });
    cout << "Book added successfully!" << endl;
}

// Function to delete a book from the library
void delete_book(vector<Book>& library, int bookId) {
    // Implement book deletion logic here
    auto it = find_if(library.begin(), library.end(), [bookId](const Book& book) {
        return book.id == bookId;
    });

    if (it != library.end()) {
        library.erase(it);
        cout << "Book deleted successfully!" << endl;
    } else {
        cout << "Book not found in the library." << endl;
    }
}

// Function to borrow a book from the library
void borrow_book(const vector<Book>& library, int bookId) {
    // Implement book borrowing logic here
    Book book = search_book(library, bookId);

    if (book.id != -1) {
        cout << "Book Details:" << endl;
        cout << "ID: " << book.id << endl;
        cout << "Name: " << book.name << endl;
        cout << "Price: $" << book.price << endl;
        cout << "Quantity Available: " << book.quantity << endl;
    } 
    else {
        cout << "Book not found in the library." << endl;
    }
}

// Function to print the receipt of payment
void print_receipt(const vector<Book>& cart) {
    // Implement receipt printing logic here
    double total = 0.0;

    cout << "Receipt:" << endl;
    cout << "--------------------------------" << endl;
    for (const Book& book : cart) {
        cout << "Book: " << book.name << "\tQuantity: " << book.quantity << "\tTotal: $" << book.price * book.quantity << endl;
        total += book.price * book.quantity;
    }
    cout << "--------------------------------" << endl;
    cout << "Total: $" << total << endl;
}

int main() {
    vector<Book> library = {
        {1, "Book1", 10.99, 5},
        {2, "Book2", 15.99, 3},
        {3, "Book3", 7.99, 8}
    };

    vector<Book> cart;

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Search Book" << endl;
        cout << "2. Create Account" << endl;
        cout << "3. Login" << endl;
        cout << "4. Add Book" << endl;
        cout << "5. Delete Book" << endl;
        cout << "6. Borrow Book" << endl;
        cout << "7. Print Receipt" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int bookId;
                cout << "Enter Book ID to search: ";
                cin >> bookId;
                Book foundBook = search_book(library, bookId);
                if (foundBook.id != -1) {
                    cout << "Book found! Details:" << endl;
                    cout << "ID: " << foundBook.id << "\tName: " << foundBook.name << "\tPrice: $" << foundBook.price << "\tQuantity: " << foundBook.quantity << endl;
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            }
            case 2: {
                string username, password, email, validationPassword;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter validation password: ";
                cin >> validationPassword;
                create_account(username, password, email, validationPassword);
                break;
            }
            case 3: {
                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                bool loggedIn = login(username, password);
                if (loggedIn) {
                    cout << "Login successful!" << endl;
                } else {
                    cout << "Login failed. Invalid username or password." << endl;
                }
                break;
            }
            case 4: {
                int id, quantity;
                string name;
                double price;
                cout << "Enter Book ID: ";
                cin >> id;
                cout << "Enter Book Name: ";
                cin >> name;
                cout << "Enter Book Price: $";
                cin >> price;
                cout << "Enter Quantity: ";
                cin >> quantity;
                add_book(library, id, name, price, quantity);
                break;
            }
            case 5: {
                int bookId;
                cout << "Enter Book ID to delete: ";
                cin >> bookId;
                delete_book(library, bookId);
                break;
            }
            case 6: {
                int bookId;
                cout << "Enter Book ID to borrow: ";
                cin >> bookId;
                borrow_book(library, bookId);
                break;
            }
            case 7: {
                print_receipt(cart);
                break;
            }
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
