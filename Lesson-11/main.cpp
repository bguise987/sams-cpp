#include <iostream>

#include "PromptModule.h"
#include "ErrorHandlingModule.h"

using namespace std;

float GetDividend(void)
{
    float Dividend = 0;

    cout << "Dividend: ";
    cin >> Dividend;

    return Dividend;
}

float GetDivisor(void)
{
    float Divisor = 1;

    cout << "Divisor: ";
    cin >> Divisor;

    return Divisor;
}

float Divide(const float theDividend, const float theDivisor)
{
    return (theDividend/theDivisor);
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
        };
    }
    while (SAMSPrompt::UserWantsToContinueYOrN("More? "));

    return 0;
}