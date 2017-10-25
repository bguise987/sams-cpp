#ifndef PromptModuleH
#define PromptModuleH

namespace SAMSPrompt
{
    void PauseForUserAcknowledgement(void);

    bool UserWantsToContinue(const char *theThingWeAreDoing);
}

#endif
