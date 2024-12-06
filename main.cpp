// Kit Pollinger
//  210 Lab 37 | Hash Table
#include <iostream>
#include <string>  // For string
#include <fstream> // For Part 2 and 3
#include <map>     // For part 3
#include <list>    // For Part 3
using namespace std;

// Function to calculate the sum of ASCII values in a string
/*
int sum_ascii(const string& str) {
    int sum = 0;
    for (char ch : str) {
        sum += (int)ch; // Convert each character to its ASCII value and add to the sum
    }
    return sum;
}
*/

// Change sum_Ascii to gen_hash_Index
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
    /* Part 1 and 2
    
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

        cout << "Part 2: \n";

        const string filename = "lab-37-data.txt"; // Name of the dataset file
        ifstream infile(filename);                 // Open the file for reading

        if (!infile)
        {
            cout << "Error: Could not open file!" << endl;
            return 1;
        }

        string codeLine;
        long long lineTotal = 0; // Use long long for large numbers

        // Read each line from the file, calculate ASCII sum, and add to the grand total
        while (infile >> codeLine)
        {
            lineTotal += sum_ascii(codeLine);
        }

        infile.close(); // Close the file

        // Output the  total ASCII Sum from File
        cout << " Total ASCII Sum: " << lineTotal << endl;
        return 0;
    } */

    cout << "Part 3: \n";

    const string filename = "lab-37-data.txt"; // Name of the dataset file
    ifstream infile(filename);                 // Open the file for reading

    if (!infile)
    {
        cout << "Error: Could not open file!" << endl;
        return 1;
    }

    string codeLine;
    map<int, list<string>> hash_table;

    while (infile >> codeLine)
    {
        int hash_index = gen_hash_index(codeLine);  // Generates hash index
        hash_table[hash_index].push_back(codeLine); // Insert the code into the list at that hash index
    }
    infile.close();

    // Display  first 100 entries of the hash table
    int count = 0;
    for (const auto& entry : hash_table)
    {
        if (count++ >= 100)
            break; // Limit to the first 100 entries
        cout << "Hash Index: " << entry.first << endl;
        cout << "Codes: ";
        for (const string& code : entry.second)
        {
            cout << code << " ";
        }
        cout << endl;
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
