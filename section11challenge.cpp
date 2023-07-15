// Section 11
// Challenge
/*
     Recall the challenge from Section 9 below.
    Your challenge for section 11 is to modularize your solution to the Section 9
    challenge by refactoring your solution so that it uses uses functions.

    You decide how to modularize the program.
    you can use my solution which is included in this file, or modularize your solution.

    Here are a few hints:
        - Create functions for each major function
        - Keep the functions small
        - Remember the Boss/Worker analogy
        - Keep the vector declaration in the main function and pass the vector object
          to any function that requires it

        DO NOT move the vector object outside main and make it a global variable.

        - You can start by defining a function that displays the menu
        - You can then define a function that reads the selection from the user and returns it in uppercase
        - Create functions for each menu option
        - Create functions that display the list of numbers, calculates the mean and so forth

    Take it one function at a time and take your time.
    If you get frustrated, take a break -- this isn't as easy as it looks the first time you do it!

    Finally,  don't forget to use function prototypes!

    Good luck -- I know you can do it!
*/
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

void display_menu();
char get_selection();
void print_numbers(const vector<int> &vec);
void add_number(int num, vector<int> &vec);
void mean_numbers(const vector<int> &vec);
void smallest_number(const vector<int> &vec);
void largest_number(const vector<int> &vec);
bool search_number(int num_to_find, const vector<int> &vec);
void clear_list(vector<int> &vec);
void check_duplicate(const vector<int> &vec);
void goodbye();
void invalid_input();

int main()
{
    char input{};
    vector<int> vec;
    do
    {
        display_menu();
        input = get_selection();
        switch (input)
        {
        case 'p':
        {
            print_numbers(vec);
            break;
        }
        case 'a':
        {
            cout << "\nPlease enter an integer." << endl;
            int num_to_add{};
            cin >> num_to_add;
            add_number(num_to_add, vec);
            break;
        }
        case 'm':
        {
            mean_numbers(vec);
            break;
        }
        case 's':
        {
            smallest_number(vec);
            break;
        }
        case 'l':
        {
            largest_number(vec);
            break;
        }
        case 'q':
        {
            goodbye();
            break;
        }
        case 'f':
        {
            cout << "Enter the number you wish to find" << endl;
            int num_to_find{};
            cin >> num_to_find;
            if (search_number(num_to_find, vec))
            {
                cout << num_to_find << " exists in the list" << endl;
            }
            else
            {
                cout << num_to_find << " does not exist in the list." << endl;
            }
            break;
        }
        case 'c':
        {
            clear_list(vec);
            break;
        }
        case 'd':
        {
            check_duplicate(vec);
            break;
        }
        default:
        {
            invalid_input();
            break;
        }
        }
    } while (input != 'q');

    return 0;
}

void display_menu()
{
    cout << "\nP - Print numbers" << endl
         << "A - Add a number" << endl
         << "C - Clear list" << endl
         << "D - Check if there are duplicated entries in the list" << endl
         << "F - Find if desired number is included in the list" << endl
         << "M - Display mean of the numbers" << endl
         << "S - Display the smallest number" << endl
         << "L - Display the largest number" << endl
         << "Q - Quit" << endl
         << "\nEnter your choice:" << endl;
}

char get_selection()
{
    char input{};
    cin >> input;
    return tolower(input);
}

void print_numbers(const vector<int> &vec)
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
}

void add_number(int num, vector<int> &vec)
{
    vec.push_back(num);
    cout << "\n"
         << num << " is added." << endl;
}

void mean_numbers(const vector<int> &vec)
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
}
void smallest_number(const vector<int> &vec)
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
}
void largest_number(const vector<int> &vec)
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
}

bool search_number(int num_to_find, const vector<int> &vec)
{

    for (auto num : vec)
    {
        if (num == num_to_find)
        {
            return true;
        }
    }

    return false;
}

void clear_list(vector<int> &vec)
{
    vec.clear();
}

void check_duplicate(const vector<int> &vec)
{
    if (vec.size() == 0 || vec.size() == 1)
    {
        cout << "No duplicated entries in this list" << endl;
    }
    else
    {
        for (size_t i = 0; i < vec.size() - 1; i++)
        {
            for (size_t j = i + 1; j < vec.size(); j++)
            {
                if (vec[i] == vec[j])
                {
                    cout << "There are duplicated entries in this list." << endl;
                    return;
                }
            }
        }
        cout << "There are no duplicated entries in this list." << endl;
    }
}

void goodbye()
{
    cout << "\nGoodbye!" << endl;
}

void invalid_input()
{
    cout << "\nInvalid input, please try again" << endl;
}