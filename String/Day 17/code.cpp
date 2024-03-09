#include <iostream>
#include<vector>
using namespace std;

// Q1. Longest Common Prefix in an Array.

// Q2. Roman Number to Integer.
int num(char c)
{
    if (c == 'I')
        return 1;
    if (c == 'V')
        return 5;
    if (c == 'X')
        return 10;
    if (c == 'L')
        return 50;
    if (c == 'C')
        return 100;
    if (c == 'D')
        return 500;
    if (c == 'M')
        return 1000;
}

int romanToDecimal(string &str)
{
    // code here
    int sum = 0, index = 0;
    while (index <= str.size() - 1)
    {
        if (num(str[index]) < num(str[index + 1]))
            sum -= num(str[index]);
        else
            sum += num(str[index]);
        index++;
    }
    // sum += num(str[str.size() - 1]);
    return sum;
}

// Q3. Length of Last Word.
int lengthOfLastWord(string s)
{
    int index = s.size() - 1;
    int count = 0;

    while (index >= 0 && s[index] == ' ')
    {
        index--;
    }

    while (index >= 0 && s[index] != ' ')
    {
        count++;
        index--;
    }

    return count;
}

// Q4. Longest Distinct characters in string.
int longestSubstrDistinctChars(string S)
{
    // your code here
    vector<bool> count(256, 0);
    int first = 0, second = 0, len = 0;
    while (second < S.size())
    {
        while (count[S[second]])
        {
            count[S[first]] = 0;
            first++;
        }
        count[S[second]] = 1;
        len = max(len, second - first + 1);
        second++;
    }
    return len;
}

int main() {}