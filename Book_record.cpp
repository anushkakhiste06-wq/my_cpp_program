#include <iostream>
#include <string>
using namespace std;

class Book {
    int BookId;
    char BookName[25];
    char BookAuthor[25];
    double BookPrice;
    int year_publication;
    char name_publication[30];

public:
    static int bookCount;
    void getInfo();
    void putInfo();
    static void displayCount();
};

// Define static variable
int Book::bookCount = 0;

void Book::getInfo() {
    cout << "Enter book id: ";
    cin >> BookId;
    cin.ignore(); // clear newline

    cout << "Enter book name: ";
    cin.getline(BookName, 25);

    cout << "Enter book author: ";
    cin.getline(BookAuthor, 25);

    cout << "Enter the price of book: ";
    cin >> BookPrice;

    cout << "Enter year of publication: ";
    cin >> year_publication;
    cin.ignore();

    cout << "Enter name of publication: ";
    cin.getline(name_publication, 30);

    bookCount++;
}

void Book::putInfo() {
    cout << "\nBook ID: " << BookId;
    cout << "\nBook Name: " << BookName;
    cout << "\nBook Author: " << BookAuthor;
    cout << "\nBook Price: $ " << BookPrice;
    cout << "\nYear of Publication: " << year_publication;
    cout << "\nName of Publication: " << name_publication << endl;
}

void Book::displayCount() {
    cout << "\nTotal number of books: " << bookCount << endl;
}

int main() {
    int n;
    cout << "How many book records do you want to store? ";
    cin >> n;

    // Dynamically allocate array of objects
    Book* list = new Book[n];

    cout << "\nEnter " << n << " records:\n";
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter the details of book " << i + 1 << ":\n";
        list[i].getInfo();
    }

    cout << "\n--- Summary ---\n";
    for (int i = 0; i < n; ++i) {
        list[i].putInfo();
    }

    Book::displayCount();

    // Free memory
    delete[] list;
    return 0;
}

