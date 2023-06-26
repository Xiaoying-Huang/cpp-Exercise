#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vector1{};
    vector<int> vector2{};

    vector1.push_back(10);
    vector1.push_back(20);

    cout << "\nElement 1 of vector1: " << vector1.at(0) << endl;
    cout << "\nElement 2 of vector1: " << vector1.at(1) << endl;
    cout << "\n The size of vector1 is: " << vector1.size() << endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout << "\nElement 1 of vector2: " << vector2.at(0) << endl;
    cout << "\nElement 2 of vector2: " << vector2.at(1) << endl;
    cout << "\n The size of vector2 is: " << vector2.size() << endl;

    vector<vector<int>> vector_2d{};
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << "\nElement [0][0] of vector2_d: " << vector_2d.at(0).at(0) << endl;
    cout << "\nElement [0][1] of vector2: " << vector_2d.at(0).at(1) << endl;
    cout << "\nElement [1][0] of vector2: " << vector_2d.at(0).at(0) << endl;
    cout << "\nElement [1][1] of vector2: " << vector_2d.at(0).at(1) << endl;
    cout << "\n The size of vector2 is: " << vector_2d.size() << endl;

    vector1.at(0) = 1000;

    cout << "\nElement [0][0] of vector2_d: " << vector_2d.at(0).at(0) << endl;
    cout << "\nElement [0][1] of vector2_d: " << vector_2d.at(0).at(1) << endl;
    cout << "\nElement [1][0] of vector2_d: " << vector_2d.at(0).at(0) << endl;
    cout << "\nElement [1][1] of vector2_d: " << vector_2d.at(0).at(1) << endl;
    cout << "\n The size of vector2 is: " << vector_2d.size() << endl;

    cout << "\nElement 1 of vector1: " << vector1.at(0) << endl;
    cout << "\nElement 2 of vector1: " << vector1.at(1) << endl;
    cout << "\n The size of vector1 is: " << vector1.size() << endl;

    return 0;
}