#include <iostream>
#include <string>
#include "notepad.h"

using namespace std;

int main() {
    int choice;
    string filename;
    
    cout << "Enter the filename to work with: ";
    cin >> filename;
    
    do {
        cout << "\n=== NOTEPAD MENU ===" << endl;
        cout << "1. Create and Write to File" << endl;
        cout << "2. Read and Display File" << endl;
        cout << "3. Append Text to File" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        cin.ignore();
        
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
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        
    } while (choice != 4);
    
    return 0;
}
