// Kit Pollinger
//  210 Lab 38 | Hash Table 2
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

//Voids
void printEntries(const map<int, list<string>>& hash_table);
void search_key(const map<int, list<string>>& hash_table);
void add_key(map<int, list<string>>& hash_table);
void remove_key(map<int, list<string>>& hash_table);
void modify_key(map<int, list<string>>& hash_table)

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

    //Moved 100 Entries to a void
    int userChoice = 0;

    while (userChoice != 6){
    cout << "\n--- Hash Table Interactive Menu ---" << endl;
        cout << "[1] Print the first 100 entries" << endl;
        cout << "[2] Search for a key" << endl;
        cout << "[3] Add a key" << endl;
        cout << "[4] Remove a key" << endl;
        cout << "[5] Modify a key" << endl;
        cout << "[6] Exit" << endl;
        cout << "Enter your choice: ";
        cin >> userChoice;
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

// print first 100 entries of the hash table
void printEntries(const map<int, list<string>>& hash_table) {
    int count = 0;
    for (const auto& entry : hash_table) {
        if (count++ >= 100) break; // Limit to the first 100 entries
        cout << "Hash Index: " << entry.first << endl;
        cout << "Codes: ";
        for (const string& code : entry.second) {
            cout << code << " ";
        }
        cout << endl;
    }
}

// search key in the hash table
void search_key(const map<int, list<string>>& hash_table) {
    int key;
    cout << "Enter the hash index to search for: ";
    cin >> key;

    auto it = hash_table.find(key);
    if (it != hash_table.end()) {
        cout << "Hash Index: " << key << endl;
        cout << "Codes: ";
        for (const string& code : it->second) {
            cout << code << " ";
        }
        cout << endl;
    } else {
        cout << "Key not found in the hash table." << endl;
    }
}

//add a new key and code to the hash table
void add_key(map<int, list<string>>& hash_table) {
    string new_code;
    cout << "Enter the 12-character code to add: ";
    cin >> new_code;

    int hash_index = gen_hash_index(new_code);
    hash_table[hash_index].push_back(new_code);
    cout << "Code added to hash index " << hash_index << "." << endl;
}

//remove  key from the hash table
void remove_key(map<int, list<string>>& hash_table) {
    int key;
    cout << "Enter the hash index to remove: ";
    cin >> key;

    if (hash_table.erase(key)) {
        cout << "Key " << key << " removed from the hash table." << endl;
    } else {
        cout << "Key not found in the hash table." << endl;
    }
}

//modify key in the hash table
void modify_key(map<int, list<string>>& hash_table) {
    int key;
    cout << "Enter the hash index to modify: ";
    cin >> key;

    auto it = hash_table.find(key);
    if (it != hash_table.end()) {
        string new_code;
        cout << "Enter the new 12-character code: ";
        cin >> new_code;

        it->second.push_back(new_code);
        cout << "Code added to hash index " << key << "." << endl;
    } else {
        cout << "Key not found in the hash table." << endl;
    }
}