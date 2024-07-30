#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int add(string numbers)
{
    stringstream numberStream(numbers);
    int sumOfNumbers = 0;
    int currentNumber;
    char customeDelimiter;
    char delimiter;

    numberStream >> delimiter;
    numberStream >> delimiter;

    numberStream >> customeDelimiter;

    // Read numbers separated by commas or newlines
    while (numberStream >> currentNumber) {
        sumOfNumbers += currentNumber;

        // Read the next character to check if it's a comma or newline
        if (numberStream >> delimiter) {
            if(delimiter == customeDelimiter)
                continue;

            // Case number saperated by new line. 
            if(delimiter == '\\') {
                if(numberStream >> delimiter && delimiter != 'n')
                    return -1;
            }
        }
    }

    return sumOfNumbers;
}

int main()
{
    string numbers;
    cout << "Enter Sequence of number saperated by commas or enter number in new-line (For stop taking input press ctrl + D) : " << endl;

    // Scan multi-line input from.
    string currLine;
    while (getline(cin, currLine))
    {
        numbers += currLine;
        numbers += "\\n";
    }

    cout << numbers << endl;

    //We assume that input will be correct.
    int sumOfNumbers = add(numbers);

    // There is some mistake in input.
    if (sumOfNumbers == -1)
    {
        cout << "There is wrong input. Because, there should be number after comma but there is not any number after comma." << endl;
        return 0;
    }

    // Print the result of the sum of numbers
    cout << "The sum of the numbers is: " << sumOfNumbers << endl;

    return 0;
}