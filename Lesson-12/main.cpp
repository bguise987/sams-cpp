#include <iostream>

#include "PromptModule.h"
#include "ErrorHandlingModule.h"

using namespace std;

char GetOperator(void)
{
    char Operator = 'c';

    cout << "Operator: ";
    cin >> Operator;

    return Operator;
}

float GetOperand(void)
{
    float Operand = 1;

    cout << "Operand: ";
    cin >> Operand;

    return Operand;
}

void Tape(const char theOperator, const float theOperand)
{
    static const int myTapeSize = 20;   // Array size

    static char myOperator[myTapeSize]; // Operator part
    static float myOperand[myTapeSize]; // Operand part

    static int myNumberOfEntries = 0;   // What's in tape now

    // Remember that arrays start with element 0
    // And that the highest element is the size - 1;

    if (theOperator != '?') // Add to the tape
    {
        if (myNumberOfEntries < myTapeSize) // We have room
        {
            myOperator[myNumberOfEntries] = theOperator;
            myOperand[myNumberOfEntries] = theOperand;
            myNumberOfEntries++;
        }
        else    // About to overflow the array
        {
            throw runtime_error("Error - Out of room on the tape.");
        };
    }
    else    // Display the tape
    {
        for (int Index = 0; Index < myNumberOfEntries; Index++)
        {
            cout << myOperator[Index] << "," << myOperand[Index] << endl;
        };
    };
}

float Accumulate(const char theOperator, const float theOperand)
{
    static float myAccumulator = 0; // Initialized to 0 when the program starts

    switch (theOperator)
    {
        case '+':
            myAccumulator = myAccumulator + theOperand;
            break;
        case '-':
            myAccumulator = myAccumulator - theOperand;
            break;
        case '*':
            myAccumulator = myAccumulator * theOperand;
            break;
        case '/':
            myAccumulator = myAccumulator / theOperand;
            break;
        case '?':
            break;

        default:
            throw runtime_error("Error - Invalid operator");
    };

    Tape(theOperator, theOperand);

    return myAccumulator;
}

int main(int argc, char* argv[])
{
    SAMSErrorHandling::Initialize();

    do  // Do at least once...
    {
        try
        {
            char Operator = GetOperator();
            float Operand = GetOperand();

            cout << Accumulate(Operator, Operand) << endl;
        }
        catch (runtime_error RuntimeError)
        {
            SAMSErrorHandling::HandleRuntimeError(RuntimeError);
        }
        catch (...)
        {
            SAMSErrorHandling::HandleNotANumberError();
        };
    }
    while (SAMSPrompt::UserWantsToContinueYOrN("More? "));

    return 0;
}