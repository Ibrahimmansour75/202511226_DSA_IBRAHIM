#include <iostream>
#include <string>
#include "notepad.h"

using namespace std;

int main() {
    int choice;
    string filename;

    // Ask the user for the filename at the start
    cout << "Enter the filename to work with (e.g., notes.txt): ";
    getline(cin, filename);

    // Loop for the menu system
    do {
        cout << "\n====== SIMPLE NOTEPAD ======\n";
        cout << "1. Write File\n";
        cout << "2. Read File\n";
        cout << "3. Append File\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        
        cin >> choice;
        cin.ignore(); // Clear the buffer after reading an integer

        // Handle menu choices using switch statement
        switch (choice) {
            case 1:
                writeFile(filename);
                break;
            case 2:
                readFile(filename);
                break;
            case 3:
                appendFile(filename);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4); // Loop continues until user chooses option 4

    return 0;
}
