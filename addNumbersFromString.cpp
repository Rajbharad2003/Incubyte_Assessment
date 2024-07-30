#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int add(string numbers)
{
    stringstream numberStream(numbers);

    int num1, num2;
    int sum = 0;
    char comma;

    if (numberStream >> num1) {
        if (numberStream >> comma) {
            if (comma == ',' && numberStream >> num2) {
                // Case with two numbers separated by a comma.
                sum = num1 + num2;
                return sum;
            }
            else {
                // Case with there is no number after comma.
                return -1;
            }
        }
        else {
            // Case with only one number.
            return num1;
        }
    }
    else {
        // case with there is no any number in string.
        return sum;
    }
    return sum;
}

int main()
{
    string numbers;
    cout << "Enter Sequence of number : ";
    cin >> numbers;

    int sumOfString = add(numbers);

    if(sumOfString == -1)
    {
        cout << "There is wrong input. Because, there should be number after comma but there is not any number after comma." << endl;

        return 0;
    }

    cout << "Answer of your number of string is : " << sumOfString << endl;
    return 0;
}