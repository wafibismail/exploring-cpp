/*
 * File: PromptForValidInteger.cpp
 * -------------------------------
 * This file contains and demonstrates the use of the sole
 * function getInteger which prompts for an integer, and asks
 * again if an invalid integer is entered.
 */

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

/* Function prototype */

int getInteger(string prompt);

/* Main program */

int main() {
    cout << getInteger("Enter an integer: ");
}

/*
 * Function: getInteger
 * Usage: int n = getInteger(prompt);
 * ----------------------------------
 * Requests an integer value from the user. The function begins by
 * printing the prompt string on the console and then waits for the
 * user to enter a line of input data. If that line contains a
 * single integer, the function returns the corresponding integer
 * value. If the input is not a legal integer or if extraneous
 * characters (other than whitespace) appear on the input line,
 * the implementation gives the user a chance to reenter the value.
 */

int getInteger(string prompt) {
    int value;
    string line;
    while (true) {
        cout << prompt;
        getline(cin, line);
        istringstream stream(line);
        stream >> value >> ws;
        if (!stream.fail() && stream.eof()) break;
        cout << "Illegal integer format. Try again." << endl;
    }
    return value;
}