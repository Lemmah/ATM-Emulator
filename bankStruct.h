#define BANKNAME "Funny Bank Kenya."

// Structure of a normal account holder.
struct accountHolder{
    int accNo;
    char accName[50];
    int cardNum;
    int accountBal;
}accDetails[5]; // This has limited me to five account holders at the moment, just for memory safety.
