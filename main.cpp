// Kit Pollinger
//  210 Lab 37 | Hash Table
#include <iostream>
#include <string>  // For string
#include <fstream> // For Part 2 and 3
#include <map> // For part 3
#include <list> // For Part 3
using namespace std;

// Function to calculate the sum of ASCII values in a string
int gen_hash_index(const string &str)
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
   //Removed Demo Code and Part 1 - 2
   cout << "Part 3: \n";

    const string filename = "lab-37-data.txt"; // Name of the dataset file
    ifstream infile(filename);                 // Open the file for reading

    if (!infile)
    {
        cout << "Error: Could not open file!" << endl;
        return 1;
    }
    return 0;
}
/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
