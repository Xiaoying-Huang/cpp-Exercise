// Section 9
// Challenge
/*
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.

    Your program should display a menu options to the user as follows:

    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:

The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space.
For example, [ 1 2 3 4 5 ]

If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!

*/
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    char input{};
    vector<int> vec;
    do
    {
        cout << "\nP - Print numbers\nA - Add a number\nM - Display mean of the numbers\nS - Display the smallest number\nL - Display the largest number\nQ - Quit\n\nEnter your choice:" << endl;

        cin >> input;

        input = tolower(input);

        switch (input)
        {
        case 'p':
        {
            if (vec.size() == 0)
            {
                cout << "\n[] - the list is empty" << endl;
            }
            else
            {
                cout << "\n[";
                for (int i = 0; i < vec.size(); i++)
                {
                    if (i == vec.size() - 1)
                        cout << vec[i];
                    else
                        cout << vec[i] << " ";
                }
                cout << "]" << endl;
            }
            break;
        }
        case 'a':
        {
            cout << "\nPlease enter an integer." << endl;
            int num_to_add{};
            cin >> num_to_add;
            vec.push_back(num_to_add);
            cout << "\n"
                 << num_to_add << " is added." << endl;
            break;
        }
        case 'm':
        {
            if (vec.size() == 0)
            {
                cout << "\nUnable to calculate the mean - no data" << endl;
            }
            else
            {
                float average{};
                int sum{};
                for (int i : vec)
                {
                    sum += i;
                }
                average = static_cast<float>(sum) / vec.size();
                cout << "\nThe average of the elements of the list is " << average << "." << endl;
            }
            break;
        }
        case 's':
        {
            if (vec.size() == 0)
            {
                cout << "\nUnable to determine the smallest number - list is empty" << endl;
            }
            else
            {
                int smallest{vec[0]};
                for (int i = 0; i < vec.size(); i++)
                {
                    if (vec[i] < smallest)
                    {
                        smallest = vec[i];
                    }
                }
                cout << "\nThe smallest number is " << smallest << "." << endl;
            }
            break;
        }
        case 'l':
        {
            if (vec.size() == 0)
            {
                cout << "\nUnable to determine the largest number - list is empty" << endl;
            }
            else
            {
                int largest{vec[0]};
                for (int i = 0; i < vec.size(); i++)
                {
                    if (vec[i] > largest)
                    {
                        largest = vec[i];
                    }
                }
                cout << "\nThe largest number is " << largest << "." << endl;
            }
            break;
        }
        case 'q':
        {
            cout << "\nGoodbye!" << endl;
            break;
        }
        default:
        {
            cout << "\nInvalid input, please try again" << endl;
            break;
        }
        }
    } while (input != 'q');

    return 0;
}
