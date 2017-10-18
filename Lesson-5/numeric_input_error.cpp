#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int ReturnCode = 0;

    float Dividend = 0;
    cout << "Dividend: ";
    cin >> Dividend;

    if (!cin.fail()) // Dividend is a number
    {
        float Divisor = 1;
        cout << "Divisor: ";
        cin >> Divisor;

        if (!cin.fail())    // Divisor is a number
        {
            float Result = (Dividend/Divisor);
            cout << Result << endl;
        }
        else    // Divisor is not a number
        {
            cerr << "Input error, not a number?" << endl;

            cin.clear();    // Reset the input failure bits
            // Eat the bad input so we can pause the program
            char BadInput[5];   // Up to 5 characters
            cin >> BadInput;

            // See what was thrown away
            cout << BadInput;

            ReturnCode = 1;
        };
    }
    else    // Dividend is not a number
    {
        cerr << "Input error, not a number?" << endl;

        cin.clear();    // Reset the input failure indicators
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