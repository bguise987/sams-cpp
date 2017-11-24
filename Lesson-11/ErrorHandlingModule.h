#ifndef ErrorHandlingModuleH
#define ErrorHandlingModuleH

using namespace std;

namespace SAMSErrorHandling
{
    void Initialize(void);
    int HandleNotANumberError(void);    // Returns error code
    int HandleRuntimeError(runtime_error theRuntimeError);    // Returns error code
}

#endif
