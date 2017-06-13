// Our bank acc struct.
#include "bankStruct.h"
// Our ATM sequence of events
#include "events.h"

int main(void)
{
    // Welcome user and prompt for choice of language of preference.
    printf("Welcome to %s ATM!\n%s.", BANKNAME,SLOGAN);

    // select Language
    int language = selectLanguage();

    // Input and validate PIN
    validatePin(language);

    // Start Active transaction session
    int transactionActive = 1;
    do{
        transact(inflateMenu(language));
        printf("\nDo you wish to perform another transaction?.\n\t1. Yes\t2. No\nSelection: ");
        scanf("%d", &transactionActive);
    }while(transactionActive == 1);

    // Good bye after Transaction
    (language == 1)? printf("\nBye bye! Will miss your money!\n") : printf("\nKwaheri! Tuma pesa vizuri nanii!\n");

    return 0;
}
