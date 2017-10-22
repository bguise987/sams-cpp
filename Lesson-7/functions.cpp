#include <iostream>

using namespace std;

void Initialize(void)   // No return value, no arguments
{
    cin.exceptions(cin.failbit);
}

float GetDividend(void) // Returns dividend, a float
{
    float Dividend = 0;

    cout << "Dividend: ";
    cin >> Dividend;

    return Dividend;    // Returns a copy of Dividend
}

float GetDivisor(void)  // Returns the Divisor
{
    float Divisor = 1;

    cout << "Divisor: ";
    cin >> Divisor;

    return Divisor;
}

float Divide(const float theDividend, const float theDivisor) // Takes unmodifiable (const) args, returns float
{
    return (theDividend / theDivisor);  // Returns the result of the calculation
}

int HandleNotANumberError(void) // Returns the error code
{
    cerr << "Input error - input may not have been a number." << endl;

    cin.clear();    // Clear the error state from the stream

    // Eat the bad input so we can pause the program
    char BadInput[5];
    cin >> BadInput;

    return 1;   // An error occurred
}

void PauseForUserAcknolwedgement(void)
{
    // Note: You must type something before the Enter key
    char StopCharacter;
    cout << endl << "Press a key and \"Enter\": ";
    cin >> StopCharacter;
}

int main(int argc, char* argv[])
{
    Initialize();   // Call the function

    int ReturnCode = 0;

    try
    {
        float Dividend = GetDividend();
        float Divisor = GetDivisor();

        cout << Divide(Dividend, Divisor) << endl;
    }
    catch (...)
    {
        ReturnCode = HandleNotANumberError();
    };

    PauseForUserAcknolwedgement();
    return ReturnCode;
}