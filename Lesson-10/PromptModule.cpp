#include <iostream>

#include "PromptModule.h"

namespace SAMSPrompt
{

    using namespace std;

    void PauseForUserAcknowledgement(void)
    {
        // Note: You must type something before Enter
        char StopCharacter;
        cout << endl << "Press a key and \"Enter\": ";
        cin >> StopCharacter;
    }

    bool UserWantsToContinue(const char *theThingWeAreDoing)
    {
        char DoneCharacter;

        cout << endl << theThingWeAreDoing << " - Press \"n\" and \"Enter\" to stop: ";

        cin >> DoneCharacter;

        return (DoneCharacter != 'n');  // true when not "n"
    }

    bool UserWantsToContinueYOrN(const char *theThingWeAreDoing)
    {
        char DoneCharacter;

        do
        {
            cout << endl << theThingWeAreDoing << " - Press \"n\" and \"Enter\" to stop: ";

            cin >> DoneCharacter;

            if
            (
                !
                (
                    (DoneCharacter == 'y')
                    ||
                    (DoneCharacter == 'n')
                )
            )
            {
                cout << "...Error - " << "please ener \"y\" or \"n\"." << endl;
            };
        }
        while
        (
            !
            (
                (DoneCharacter == 'y')
                ||
                (DoneCharacter == 'n')
            )
        );

        return (DoneCharacter != 'n');
    }

}
