#include <iostream>
#include <vector>
using namespace std;

// Q1. Remove all duplicates from a given string.
string removeDuplicates(string str)
{
    // code here
    string ans = "";
    vector<bool> occurance(256, 0);
    int index = 0;

    while (index < str.size())
    {
        if (!occurance[str[index]])
        {
            ans += str[index];
            occurance[str[index]] = 1;
        }
        index++;
    }
    return ans;
}

// Q2. Min Number of Flips.
int minFlips(string S)
{
    // your code here
    int count1 = 0, count2 = 0;
    char active = '0';
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] != active)
        {
            count1++;
            if (active == '0')
                active = '1';
            else
                active = '0';
        }
        else
        {
            if (active == '0')
                active = '1';
            else
                active = '0';
        }
    }

    active = '1';
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] != active)
        {
            S[i] = '1';
            count2++;
            if (active == '0')
                active = '1';
            else
                active = '0';
        }
        else
        {
            if (active == '0')
                active = '1';
            else
                active = '0';
        }
    }

    return min(count1, count2);
}

// Q3. Meta Strings.
bool metaStrings(string S1, string S2)
{
    // your code here
    if (S1.size() != S2.size())
        return 0;

    int count = 0;

    int index1 = -1, index2 = -1;
    for (int i = 0; i < S1.size(); i++)
    {
        if (S1[i] != S2[i])
        {
            count++;
            if (count == 1)
                index1 = i;
            if (count == 2)
                index2 = i;
        }
    }

    if (count == 2 && S1[index1] == S2[index2] && S1[index2] == S2[index1])
        return 1;
    return 0;
}

int main() {}