#include <iostream>

#include "PromptModule.h"

using namespace std;

void PauseForUserAcknowledgement(void)
{
    // Note: You must type something before Enter
    char StopCharacter;
    cout << endl << "Press a key and \"Enter\": ";
    cin >> StopCharacter;
}
