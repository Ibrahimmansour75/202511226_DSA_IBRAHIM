#include <iostream>
#include "Functions.h"

using namespace std;

int main()
{
    int choice;

    do
    {
        cout << "\n===== LIBRARY MENU =====\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search Book by ID\n";
        cout << "6. Display Overdue Books\n";
        cout << "7. Calculate Total Fines\n";
        cout << "8. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            borrowBookMenu();
            break;

        case 4:
            returnBookMenu();
            break;

        case 5:
            searchBook();
            break;

        case 6:
            displayOverdueBooks();
            break;

        case 7:
            calculateTotalFines();
            break;

        case 8:
            cout << "Program Ended\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while(choice != 8);

    return 0;
}
