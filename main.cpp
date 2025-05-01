#include"header.h";


int main() 
{
    /*
    string data= "(A+B)*[C-{D/E}]";

    cout << balance(data);
    */




    stringStack s;
    
    int choice;
    string input;

    while (true) {

        cout << "1. Type text\n2. Delete last character\n3. Undo\n4. Redo\n5. Exit\nChoose an option: ";
        cin >> choice;
        cin.ignore(); // Clear newline

        switch (choice) {
        case 1:
            cout << "Enter text to append: ";
            getline(cin, input);
            s.type(input);
            s.display();
            break;

        case 2:

            s.pop();
            s.display();
            break;

        case 3:
            s.undoFun();

            s.display();
            break;

        case 4:
            s.redoFun();

            s.display();
            break;

        case 5:
            cout << "Exiting program..." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

}