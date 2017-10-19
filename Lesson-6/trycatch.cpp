#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    // Prepare to have failed input throw an exception
    cin.exceptions(cin.failbit);

    int ReturnCode = 0;

    try // Normal processing code
    {
        float Dividend = 0;
        cout << "Dividend: ";
        cin >> Dividend;

        float Divisor = 1;
        cout << "Divisor: ";
        cin >> Divisor;

        float Result = (Dividend/Divisor);

        cout << Result << endl;
    }
    catch (...) // Error handling section
    {
        cerr <<
            "Input error, not a number?" <<
            endl;

        cin.clear();    // Clear the error state

        // Eat the bad input so we can pause the program
        char BadInput[5];   // Up to 5 characters
        cin >> BadInput;

        ReturnCode = 1;
    };

    // Note: You must type something before the Enter key
    char StopCharacter;
    cout << endl << "Press a key and \"Enter\": ";
    cin >> StopCharacter;

    return ReturnCode;
}