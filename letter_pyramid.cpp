#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "\nEnter your string to build a letter pyramid:" << endl;
    string input_str{};
    getline(cin, input_str);
    size_t str_length = input_str.size();
    string line_str{};
    for (int i = 0; i < str_length; i++)
    {
        // Displaying spaces
        size_t n_of_spaces = str_length - (i + 1);
        for (int j = 0; j < n_of_spaces; j++)
        {
            line_str += " ";
        }

        // Displaying letters
        size_t n_of_chars = 1 + 2 * i;
        string line_letters{input_str[i]};
        int k = i;
        while (line_letters.size() < n_of_chars && k >= 0)
        {
            line_letters.insert(0, 1, input_str.at(k - 1));
            line_letters.push_back(input_str[k - 1]);
            k--;
        }

        // Concatenating spaces and letters; Shifting to new line
        line_str.append(line_letters);
        line_str += '\n';
    }
    cout << "\n"
         << line_str << endl;
    return 0;
}