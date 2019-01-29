#include <stdio.h>
#include "BankAccount.h"

struct BankAccount {
    double balance;
    double last_withdrawl;
    double last_deposit;
};

BankAccount* BankAccount_construct(double balance) {
    struct BankAccount *account = malloc(sizeof(BankAccount));

    account->balance = balance;
    account->last_deposit = 0;
    account->last_withdrawl = 0;

    return account;
};

void BankAccount_destroy(BankAccount* ba) {
    free(ba);
};

int BankAccount_deposit(BankAccount* ba, double amount) {
    ba->balance = ba->balance + amount;
    ba->last_deposit = amount;

    return 1;
};

int BankAccount_withdraw(BankAccount* ba, double amount) {
    ba->balance = ba->balance - amount;
    ba->last_withdrawl = amount;

    return 1;
};

double BankAccount_get_balance(BankAccount* ba) {
    return ba->balance;
};

double BankAccount_get_last_deposit(BankAccount* ba) {
    return ba->last_deposit;
};

double BankAccount_get_last_withdrawal(BankAccount* ba) {
    return ba->last_withdrawl;
};

// int main() {
//     double initialBalance;

//     printf("Initial balance, dude ");
//     scanf("%lf", &initialBalance);

//     BankAccount* b = BankAccount_construct(initialBalance);

//     int run = 0;

//     while (!run) {
//         double amount = 0;
//         char command;

//         printf("The actions, dude:\n"
//             "a: get balance, dude\n"
//             "b: deposit money, dude\n"
//             "c: withdraw money, dude\n"
//             "d: get last deposit, dude\n"
//             "e: get_last withdrawl, dude\n"
//             "f: quit, dude\n");

//         scanf("%c", &command);

//         switch(command) {
//             case 'a':
//                 printf("Your balance is %lf \n", BankAccount_get_balance(b));
//                 continue;
//             case 'b':
//                 printf("How much do you want to deposit, dude\n");
//                 scanf("%lf", &amount);
//                 if (BankAccount_deposit(b, amount)) {
//                     printf("Successfully deposited %lf. \n", amount);
//                     continue;
//                 } else {
//                     run = 1;
//                 }
//             case 'c':
//                 printf("How much do you want to withdraw, dude\n");

//                 scanf("%lf", &amount);

//                 BankAccount_withdraw(b, amount);

//                 printf("Successfully withdrew %lf. \n", amount);
//                 continue;
//             case 'd':
//                 printf("The last deposit is: %lf. \n", BankAccount_get_last_deposit(b));
//                 continue;
//             case 'e':
//                 printf("Your last withdrawl was: %lf \n", BankAccount_get_last_withdrawal(b));
//                 continue;
//             case 'f':
//                 BankAccount_destroy(b);
//                 run = 1;
//         }
//     };

// }

/*
 * Implement the definitions for the
 * functions involving BankAccount from BankAccount.h here,
 *
 * Make sure to produce comments that look like this!
 * (Try to copy the formatting.)
 *
 * For BankAccount_construct() and BankAccount_destroy(),
 * if you do not remember malloc() and free(), review them
 * by creating a toy program.
 */

