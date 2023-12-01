#include <iostream>

using namespace std;

int main() {
    char choice;
    do {
        double num1, num2, result;
        char operation;

        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        cout << "Choose an operation:" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "Enter the number corresponding to the operation: ";
        cin >> operation;

        switch (operation) {
            case '1':
                result = num1 + num2;
                break;
            case '2':
                result = num1 - num2;
                break;
            case '3':
                result = num1 * num2;
                break;
            case '4':
               
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                    return 1; 
                }
                break;
            default:
                cout << "Error: Invalid operation." << endl;
                return 1; 
        }

        
        cout << "Result: " << result << endl;
        cout << "Do you want to perform another operation? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Calculator program exited." << endl;

    return 0; 
}
