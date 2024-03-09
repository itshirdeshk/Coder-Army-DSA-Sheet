#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Q1. Anagram of String.
int remAnagram(string str1, string str2)
{
    // Your code goes here
    int count = 0;
    int arr1[26] = {0};
    int arr2[26] = {0};

    for (int i = 0; i < str1.size(); i++)
    {
        int index = str1[i] - 'a';
        arr1[index]++;
    }

    for (int i = 0; i < str2.size(); i++)
    {
        int index = str2[i] - 'a';
        arr2[index]++;
    }
    for (int i = 0; i < 26; i++)
    {
        int dif = 0;
        if (arr1[i] > arr2[i])
        {
            dif = arr1[i] - arr2[i];
            count += dif;
        }
        else
        {
            dif = arr2[i] - arr1[i];
            count += dif;
        }
    }
    return count;
}

// Q2. Merge String.
string merge(string S1, string S2)
{
    // your code here
    string ans = "";
    int pos1 = 0, pos2 = 0;
    while (pos1 < S1.size() && pos2 < S2.size())
    {
        ans += S1[pos1++];
        ans += S2[pos2++];
    }

    while (pos1 < S1.size())
        ans += S1[pos1++];

    while (pos2 < S2.size())
        ans += S2[pos2++];

    return ans;
}

// Q3. Reverse words in a given string.
string reverseWords(string S)
{
    // code here
    int start = 0, end = S.size() - 1;
    while (start <= end)
    {
        swap(S[start++], S[end--]);
    }

    start = 0;
    end = 0;

    while (end < S.size())
    {
        if (S[end] == '.')
        {
            int s = start, e = end - 1;
            while (s < e)
            {
                swap(S[s++], S[e--]);
            }
            end++;
            start = end;
        }
        else
        {
            end++;
        }
    }

    end--;
    while (start <= end)
    {
        swap(S[start++], S[end--]);
    }

    return S;
}

// Q4. Palindrome String.
int isPalindrome(string S)
{
    // Your code goes here
    int start = 0, end = S.size() - 1;
    while (start <= end)
    {
        if (S[start] == S[end])
            start++, end--;
        else
            return 0;
    }
    return 1;
}

int main() {}