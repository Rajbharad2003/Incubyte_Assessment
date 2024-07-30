#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int add(string numbers)
{
    stringstream numberStream(numbers);
    int sumOfNumbers = 0;
    int currentNumber;
    char comma;

    // Scan the first number
    if (!(numberStream >> currentNumber)) {
        // If the first number is not valid
        return -1;
    }
    sumOfNumbers += currentNumber;

    // Scan number saperated by comma separated by comma.
    while (numberStream >> comma) { 
        if (comma != ',') {
            //There is other charactor than comma.
            return -1;
        } 

        if (!(numberStream >> currentNumber)) {
            // If there's no number after the comma
            return -1;
        }
        sumOfNumbers += currentNumber;
    }

    return sumOfNumbers;
}

int main()
{
    string numbers;
    cout << "Enter Sequence of number : ";
    cin >> numbers;

    int sumOfString = add(numbers);

    //There is some mistake in input.
    if(sumOfString == -1)
    {
        cout << "There is wrong input. Because, there should be number after comma but there is not any number after comma." << endl;

        return 0;
    }

    //print the answer of the string numbers sum.
    cout << "Answer of your number of string is : " << sumOfString << endl;

    return 0;
}