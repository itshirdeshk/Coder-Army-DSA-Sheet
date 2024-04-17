#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Q1. Reverse a String.
string reverseWord(string str)
{
    // Your code goes here
    int start = 0, end = str.size() - 1;
    while (start <= end)
    {
        swap(str[start++], str[end--]);
    }
    return str;
}

// Q2. Check if strings are rotations of each other or not.

// Q3. Maximum Occuring Character.
char getMaxOccuringChar(string str)
{
    // Your code here
    vector<int> occurance(26, 0);
    for (int i = 0; i < str.size(); i++)
    {
        int index = str[i] - 'a';
        occurance[index]++;
    }

    int max = 0;
    int index = 0;
    for (int i = 0; i < 26; i++)
    {
        if (occurance[i] > max)
        {
            index = i;
            max = occurance[i];
        }
    }

    char ans = 'a' + index;
    return ans;
}

// Q4. Binary String.
long binarySubstring(int n, string a)
{
    int count = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '1')
            count++;
    }
    return (count * (count - 1)) / 2;
}

int main() {}