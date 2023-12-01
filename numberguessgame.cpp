#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    srand(time(0));

    const int maxAttempts = 7; // Maximum number of attempts
    int secretNumber = rand() % 100 + 1;
    int guess, attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 100. Can you guess it?" << endl;

    do {
        cout << "Enter your guess (between 1 and 100): ";

        if (!(cin >> guess)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (guess < 1 || guess > 100) {
            cout << "Please enter a number between 1 and 100." << endl;
            continue;
        }

        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number (" << secretNumber << ") in " << attempts << " attempts." << endl;
            break;
        }

        if (attempts == maxAttempts) {
            cout << "Sorry, you've reached the maximum number of attempts. The correct number was " << secretNumber << "." << endl;
            break;
        }

    } while (true);

    return 0;
}
