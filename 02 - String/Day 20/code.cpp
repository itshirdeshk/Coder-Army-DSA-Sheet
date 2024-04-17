#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Q1. Sum of two large numbers.
string findSum(string X, string Y)
{
    // Your code goes here
    int index1 = X.size() - 1, index2 = Y.size() - 1, carry = 0, sum = 0;
    string ans = "";

    if (X.size() >= Y.size())
    {
        while (index2 >= 0)
        {
            sum = (X[index1--] - '0') + (Y[index2--] - '0') + carry;
            carry = sum / 10;
            ans += ('0' + (sum % 10));
        }

        while (index1 >= 0)
        {
            sum = (X[index1--] - '0') + carry;
            carry = sum / 10;
            ans += ('0' + (sum % 10));
        }

        if (carry)
        {
            ans += '1';
        }

        reverse(ans.begin(), ans.end());
    }
    else
    {
        while (index1 >= 0)
        {
            sum = (X[index1--] - '0') + (Y[index2--] - '0') + carry;
            carry = sum / 10;
            ans += ('0' + (sum % 10));
        }

        while (index2 >= 0)
        {
            sum = (Y[index2--] - '0') + carry;
            carry = sum / 10;
            ans += ('0' + (sum % 10));
        }

        if (carry)
        {
            ans += '1';
        }

        reverse(ans.begin(), ans.end());
    }

    while (ans[0] == '0')
    {
        ans.erase(0, 1);
    }
    if (ans == "")
        return "0";
    return ans;
}

// Q2. Length of the longest substring.
int longestUniqueSubsttr(string S)
{
    // code
    vector<bool> count(256);
    int first = 0, second = 0, len = 0;
    while (second < S.size())
    {
        while (count[S[second]])
        {
            count[S[first++]] = 0;
        }
        count[S[second]] = 1;
        len = max(len, second - first + 1);
        second++;
    }
    return len;
}

// Q3. Longest Prefix Suffix.
int lps(string s)
{
    // Your code goes here
    vector<int> lps(s.size(), 0);
    int pre = 0, suf = 1;
    while (suf < s.size())
    {
        if (s[pre] == s[suf])
        {
            lps[suf++] = (pre++) + 1;
        }
        else
        {
            if (pre == 0)
                lps[suf++] = 0;
            else
                pre = lps[pre - 1];
        }
    }
    return lps[s.size() - 1];
}

// Q4. Smallest distinct window.
int findSubString(string str)
{
    // Your code goes here
    vector<int> count(256, 0);
    int first = 0, second = 0, len = str.size(), diff = 0;

    // Calculate all the unique chars
    while (first < str.size())
    {
        if (count[str[first]] == 0)
        {
            diff++;
        }
        count[str[first]]++;
        first++;
    }

    for (int i = 0; i < 256; i++)
        count[i] = 0;

    first = 0;

    while (second < str.size())
    {
        while (diff && second < str.size())
        {
            if (count[str[second]] == 0)
                diff--;

            count[str[second]]++;
            second++;
        }

        len = min(len, second - first);

        while (diff != 1)
        {
            len = min(len, second - first);
            count[str[first]]--;

            if (count[str[first]] == 0)
                diff++;

            first++;
        }
    }
    return len;
}

int main() {}
