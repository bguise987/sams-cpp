#include <iostream>
#include <exception>
#include "ErrorHandlingModule.h"

using namespace std;

namespace SAMSErrorHandling
{
    using namespace std;

    void Initialize(void)
    {
        cin.exceptions(cin.failbit);
    }

    int HandleNotANumberError(void) // Returns error code
    {
        cerr << "Input error - not a number?" << endl;
        cin.clear();    // Clear error state from the stream

        // Eat the bad input so we can pause the program
        char BadInput[5];
        cin >> BadInput;

        return 1;   // An error occurred
    }

    int HandleRuntimeError(runtime_error theRuntimeError) // Returns error code
    {
        cerr << theRuntimeError.what() << endl;
        return 1;
    }
}