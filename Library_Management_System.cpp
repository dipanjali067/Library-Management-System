#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    bool issued;
};

int main() {
    Book books[100];
    int count = 0, choice;

    do {
        cout << "\n===== Library Management System =====";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "\nEnter Book ID: ";
            cin >> books[count].id;
            cin.ignore();

            cout << "Enter Book Title: ";
            getline(cin, books[count].title);

            cout << "Enter Author Name: ";
            getline(cin, books[count].author);

            books[count].issued = false;
            count++;

            cout << "Book Added Successfully!\n";
            break;

        case 2:
            if(count == 0) {
                cout << "No Books Available!\n";
            } else {
                for(int i = 0; i < count; i++) {
                    cout << "\nBook ID: " << books[i].id;
                    cout << "\nTitle: " << books[i].title;
                    cout << "\nAuthor: " << books[i].author;
                    cout << "\nStatus: "
                         << (books[i].issued ? "Issued" : "Available")
                         << "\n";
                }
            }
            break;

        case 3: {
            string title;
            cin.ignore();

            cout << "Enter Title to Search: ";
            getline(cin, title);

            bool found = false;

            for(int i = 0; i < count; i++) {
                if(books[i].title == title) {
                    cout << "\nBook Found!";
                    cout << "\nID: " << books[i].id;
                    cout << "\nAuthor: " << books[i].author;
                    found = true;
                }
            }

            if(!found)
                cout << "Book Not Found!\n";

            break;
        }

        case 4: {
            int id;
            cout << "Enter Book ID to Issue: ";
            cin >> id;

            bool found = false;

            for(int i = 0; i < count; i++) {
                if(books[i].id == id) {
                    books[i].issued = true;
                    cout << "Book Issued Successfully!\n";
                    found = true;
                }
            }

            if(!found)
                cout << "Book Not Found!\n";

            break;
        }

        case 5: {
            int id;
            cout << "Enter Book ID to Return: ";
            cin >> id;

            bool found = false;

            for(int i = 0; i < count; i++) {
                if(books[i].id == id) {
                    books[i].issued = false;
                    cout << "Book Returned Successfully!\n";
                    found = true;
                }
            }

            if(!found)
                cout << "Book Not Found!\n";

            break;
        }

        case 6:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}
