#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int selectLanguage();
int validatePin(int language);
int inflateMenu(int language); // returns the selection
void transact(int selection, int language);

// Inflate a menu of a language of users choice.
int inflateMenu(int language)
{
    // Get menu file in the language chosen.
    FILE *menuFile;
    if(language == 1) // This is English
    {
        printf("Welcome. Please Select a service.\n");
        menuFile = fopen("languages/englishMenu.txt", "r");
    }else{
        printf("Karibu. Tafadhali Chagua huduma.\n");
        menuFile = fopen("languages/kiswahiliMenu.txt", "r");
    }
    // Read menu items from file
    char menuItem[20];
    int menuItemsCount = 1;
    while(fgets(menuItem,sizeof(menuItem),menuFile))
    {
            printf("\t%d. %s",menuItemsCount,menuItem);
            menuItemsCount++;
    }

    // Get user's desired Transaction
    int transaction;
    (language == 1)? printf("\nTransaction: "): printf("Huduma: ");
    scanf("%d", &transaction);

    return transaction;
}

void transact(int transaction, int language){
    float balance = 2000;
    float standingCharge = 500;
    float transferFee = 85;
    int amount;
    switch (transaction)
    {
        case 1:
            printf("Enter amount to withdraw: ");
            scanf("%d", &amount);
            if(amount < balance - standingCharge){
                balance -= (float) amount;
                (language == 1)?  printf("Transaction Successful. Withdrawn %.2f. Balance is %.2f.",(float) amount, balance) : printf("Huduma imeidhinishwa. Umetoa %.2f. Baki ya akaunti ni: %.2f.",(float) amount, balance);
            }else{
                (language == 1)? printf("\nYou have insufficient balance.\n") : printf("\nHuna pesa za kutosha. Umesota Jamaa!\n");
            }
            break;

        case 2:
            printf("Balance is: %.2f", balance);
            break;

        case 3:
            printf("Enter amount to transfer: ");
            scanf("%d", &amount);
            if(amount < balance - (standingCharge + transferFee)){
                balance -= (float) amount;
                (language == 1)? printf("Transaction successful. You have transfered %d.", amount): printf("Huduma imeidhinishwa. Umetuma %d", amount );
            }else{
                printf("\nYou have insufficient balance.\n");
            }
            break;

        default:
            printf("Invalid Choice.");
            break;

    }
}

int validatePin(int language){
    int pin = 2323;
    int enteredPin;
    int pinStatus = 0;
    int attempts = 3;
    do{
        attempts--;
        printf("%s", (language == 1)? "\nEnter your pin number: ": "\nWeka nambari yako ya siri: ");
        scanf("%d", &enteredPin);
        if(enteredPin == pin){
            pinStatus = 1;
        }else{
        if(attempts != 0){
            (language == 1)? printf("\nInvalid pin. You have %d more attempts.\n",attempts) : printf("\nNambari ya siri sio sahihi. Unaweza jaribu mara nyingine %d.\n", attempts);
        }else{
            (language == 1)? printf("\nYour card has been temporarily blocked. Please consult the bank. Goosebumps!") : printf("\nAccounti yako imezuiliwa. Tafadhali fika kwenye benki. Kwaheri.\nEeeh, nanii beba kadi yako!");
            exit(1);
        }
        }
    }while(pinStatus == 0);
return pinStatus;
}


int selectLanguage(){
    int language;
    int languageAvailable = 0;
    while(languageAvailable == 0)
    {
        printf("\nPlease select your language:\n\t1.English\n\t2.Kiswahili\n");
        printf("Your choice (1 or 2): ");
        scanf("%d", &language);
        // If language is not available on the list of options
        if(language == 1 || language == 2){
            languageAvailable = 1;
        }else{
            printf("Invalid choice. Please input 1 or 2.");
        }
    }
    return language;
}
