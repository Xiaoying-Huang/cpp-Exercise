// Section 8 Challenge
/*
    For this program I will be using US dollars and cents.

    Write a program that asks the user to enter the following:
    An integer representing the number of cents

    You may assume that the number of cents entered is greater than or equal to zero

    The program should then display how to provide that change to the user.

    In the US:
        1 dollar is 100 cents
        1 quarter is 25 cents
        1 dime is 10 cents
        1 nickel is 5 cents, and
        1 penny is 1 cent.

    Here is a sample run:

    Enter an amount in cents :  92

    You can provide this change as follows:
    dollars    : 0
    quarters : 3
    dimes     : 1
    nickels   : 1
    pennies  : 2

    Feel free to use your own currency system.
    Also, think of how you might solve the problem using the modulo operator.

    Have fun and test your program!!

*/
#include <iostream>

using namespace std;

int main()
{

    const int cents_per_dollar{100};
    const int cents_per_quarter{25};
    const int cents_per_dime{10};
    const int cents_per_nickel{5};

    int change_in_pennies{0};
    cout << "Enter an amount in cents :" << endl;
    cin >> change_in_pennies;

    int dollars_needed{0};
    int balance{0};
    dollars_needed = change_in_pennies / cents_per_dollar;
    balance = change_in_pennies - dollars_needed * cents_per_dollar;

    int quarters_needed{0};
    quarters_needed = balance / cents_per_quarter;
    balance = balance - quarters_needed * cents_per_quarter;

    int dimes_needed{0};
    dimes_needed = balance / cents_per_dime;
    balance = balance - dimes_needed * cents_per_dime;

    int nickels_needed{0};
    nickels_needed = balance / cents_per_nickel;
    balance -= nickels_needed * cents_per_nickel;

    int pennies_needed{0};
    pennies_needed = balance;

    cout << "\nYou can provide this change as follows:" << endl
         << "dollars: " << dollars_needed << endl
         << "quarters: " << quarters_needed << endl
         << "dimes: " << dimes_needed << endl
         << "nickels: " << nickels_needed << endl
         << "pennies: " << pennies_needed << endl;
    return 0;
}
