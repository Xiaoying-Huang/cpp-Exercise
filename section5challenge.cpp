
// Section 6
// Challenge

/*
    Frank's Carpet Cleaning Service
    Charges:
        $25 per small room
        $35 per large room
    Sales tax rate is 6%
    Estimates are valid for 30 days

    Prompt the user for the number of small and large rooms they would like cleaned
    and provide an estimate such as:

Estimate for carpet cleaning service
Number of small rooms: 3
Number of large rooms: 1
Price per small room: $25
Price per large room: $35
Cost : $110
Tax: $6.6
===============================
Total estimate: $116.6
This estimate is valid for 30 days
*/

#include <iostream>

using namespace std;

int main()
{
    cout << "How many small rooms would you like to clean? " << endl;
    int number_of_small_rooms{0};
    cin >> number_of_small_rooms;

    cout << "How many large rooms would you like to clean?" << endl;
    int number_of_large_rooms{0};
    cin >> number_of_large_rooms;

    const double price_per_small_room{25};
    const double price_per_large_room{35};
    const double sales_tax_rate{0.06};
    const int valid_period{30};

    cout << "Number of small rooms: " << number_of_small_rooms << endl
         << "Number of large rooms: " << number_of_large_rooms << endl
         << "Price per small room: $" << price_per_small_room << endl
         << "Price per large room: $" << price_per_large_room << endl;
    double cost = number_of_large_rooms * price_per_large_room + number_of_small_rooms * price_per_small_room;
    cout << "Cost : $" << cost << endl;
    double tax = cost * sales_tax_rate;
    cout << "Tax: $" << tax << endl
         << "===============================" << endl
         << "Total estimate: $" << cost + tax << endl
         << "This estimate is valid for " << valid_period << " days" << endl;

    return 0;
}