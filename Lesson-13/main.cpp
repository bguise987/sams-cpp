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
    static const int myTapeChunk = 3;

    static char *myOperator = new char[myTapeChunk]; // Operator part
    static int *myOperand = new int[myTapeChunk]; // Operand part

    static int myTapeSize = myTapeChunk;   // Array size

    static int myNumberOfEntries = 0;   // What's in tape now

    // Remember that arrays start with element 0
    // And that the highest element is the size - 1;

    switch (theOperator)
    {
        case '?': // Display the tape
            for (int Index = 0; Index < myNumberOfEntries; Index++)
            {
                cout << myOperator[Index] << "," << myOperand[Index] << endl;
            };

            break;

        case '.': // The program is stopping, delete arrays

            delete [] myOperator;
            delete [] myOperand;

            break;

        default:    // Add to the tape and expand if needed

            if (myNumberOfEntries == myTapeSize) // Expand
            {
                // Create a destination for the expansion

                char *ExpandedOperator = new char[myNumberOfEntries + myTapeChunk];

                int *ExpandedOperand = new int[myNumberOfEntries + myTapeChunk];

                // We use pointers to do the array copy, starting
                // at the array start position.
                char *FromOperator = myOperator;
                int *FromOperand = myOperand;

                char *ToOperator = ExpandedOperator;
                int *ToOperand = ExpandedOperand;

                // Copy the old arrays to the new
                // This is supposed to be faster
                // than copying arrays using indexes
                // but it is dangerous

                for (int Index = 0; Index < myNumberOfEntries; Index++)
                {
                    *ToOperator++ = *FromOperator++;
                    *ToOperand++ = *FromOperand++;
                };

                // Delete the old arrays

                delete [] myOperator;
                delete [] myOperand;

                // Replace the old pointers with the new

                myOperator = ExpandedOperator;
                myOperand = ExpandedOperand;

                // Record how big the array is now

                myTapeSize += myTapeChunk;

                // Now it's safe to add a new entry
            };

            myOperator[myNumberOfEntries] = theOperator;
            myOperand[myNumberOfEntries] = theOperand;
            myNumberOfEntries++;
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