#include "Functions.h"

LibraryBook books[100];
int totalBooks = 0;

void addBook()
{
    int id;
    string title;
    string author;

    cout << "Enter Book ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    books[totalBooks] = LibraryBook(id, title, author);
    totalBooks++;

    cout << "Book Added Successfully\n";
}

void displayBooks()
{
    if(totalBooks == 0)
    {
        cout << "No Books Available\n";
        return;
    }

    for(int i=0;i<totalBooks;i++)
    {
        cout << "\nBook ID: " << books[i].getBookID();
        cout << "\nTitle: " << books[i].getTitle();
        cout << "\nAuthor: " << books[i].getAuthor();
        cout << "\nBorrowed: ";

        if(books[i].getBorrowed())
            cout << "Yes";
        else
            cout << "No";

        cout << "\n---------------------\n";
    }
}

void searchBook()
{
    int id;
    bool found=false;

    cout << "Enter Book ID: ";
    cin >> id;

    for(int i=0;i<totalBooks;i++)
    {
        if(books[i].getBookID()==id)
        {
            cout << "\nBook Found\n";
            cout << "Title: " << books[i].getTitle() << endl;
            cout << "Author: " << books[i].getAuthor() << endl;
            found=true;
        }
    }

    if(!found)
        cout << "Book Not Found\n";
}

void borrowBookMenu()
{
    int id;
    string borrower;
    int days;

    cout << "Enter Book ID: ";
    cin >> id;

    for(int i=0;i<totalBooks;i++)
    {
        if(books[i].getBookID()==id)
        {
            if(books[i].getBorrowed())
            {
                cout << "Book Already Borrowed\n";
                return;
            }

            cin.ignore();

            cout << "Borrower Name: ";
            getline(cin, borrower);

            cout << "Days Borrowed: ";
            cin >> days;

            books[i].setBorrowerName(borrower);
            books[i].setDaysBorrowed(days);
            books[i].setBorrowed(true);

            cout << "Book Borrowed Successfully\n";
            return;
        }
    }

    cout << "Book Not Found\n";
}

void returnBookMenu()
{
    int id;

    cout << "Enter Book ID: ";
    cin >> id;

    for(int i=0;i<totalBooks;i++)
    {
        if(books[i].getBookID()==id)
        {
            books[i].setBorrowed(false);
            books[i].setBorrowerName("");
            books[i].setDaysBorrowed(0);

            cout << "Book Returned Successfully\n";
            return;
        }
    }

    cout << "Book Not Found\n";
}

void displayOverdueBooks()
{
    bool found=false;

    for(int i=0;i<totalBooks;i++)
    {
        if(books[i].getBorrowed() &&
           books[i].getDaysBorrowed()>14)
        {
            cout << "\nBook ID: "
                 << books[i].getBookID();

            cout << "\nTitle: "
                 << books[i].getTitle();

            cout << "\nDays: "
                 << books[i].getDaysBorrowed();

            cout << "\n----------------\n";

            found=true;
        }
    }

    if(!found)
        cout << "No Overdue Books\n";
}

void calculateTotalFines()
{
    double totalFine=0;

    for(int i=0;i<totalBooks;i++)
    {
        if(books[i].getBorrowed() &&
           books[i].getDaysBorrowed()>14)
        {
            totalFine +=
            (books[i].getDaysBorrowed()-14)*100;
        }
    }

    cout << "Total Fine = "
         << totalFine << " RWF\n";
}
