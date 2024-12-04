// Kit Pollinger
//  210 Lab 37 | Hash Table
#include <iostream>
#include <string>  // For string
using namespace std;

// Function to calculate the sum of ASCII values in a string
int sum_ascii(const string &str)
{
    int sum = 0;
    for (char ch : str)
    {
        sum += (int)ch; // Convert each character to its ASCII value and add to the sum
    }
    return sum;
}

int main()
{
    cout << "Demo Code:\n";
    char a = 'A';
    cout << a << endl;
    cout << (int)a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char)b << endl;
    
    // Testing the sum_ascii function
    string AsciiTest;
    cout << "Part 1: \n";
    cout << "Enter a test string: ";
    cin >> AsciiTest;

    // Output the ASCII sum
    cout << "String: " << AsciiTest << endl;
    cout << "ASCII Sum: " << sum_ascii(AsciiTest) << endl;

    return 0;
}
/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
