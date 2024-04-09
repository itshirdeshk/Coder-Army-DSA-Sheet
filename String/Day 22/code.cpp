#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Transform String.
int transform(string A, string B)
{
    // code here.
    vector<int> hash(256, 0);
    vector<int> hash2(256, 0);
    if (A.length() != B.length())
        return -1;
    for (auto it : A)
    {
        hash[it]++;
    }
    for (auto it : B)
    {
        hash2[it]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (hash[i] != hash2[i])
            return -1;
    }
    int count = 0;
    int i = A.length() - 1;
    int j = B.length() - 1;
    while (i >= 0 && j >= 0)
    {
        if (A[i] == B[j])
        {
            i--;
            j--;
        }
        else
        {
            count++;
            i--;
        }
    }
    return count;
}

// Q2. Remove and Reverse.
string removeReverse(string S)
{

    int i = 0, j = S.length() - 1;
    int map[26];
    fill(map, map + 26, 0);
    bool flag = true;
    int cnt = 0;

    for (char ch : S)
        map[ch - 'a']++;

    string begin = "", end = "";

    while (i <= j)
    {
        char ch;
        if (flag)
            ch = S[i++];
        else
            ch = S[j--];

        if (map[ch - 'a'] > 1)
        {
            map[ch - 'a']--;
            cnt++;
            flag = !flag;
        }
        else
        {
            if (flag)
                begin += ch;
            else
                end = ch + end;
        }
    }

    string ans = begin + end;
    if (cnt % 2 == 1)
        reverse(ans.begin(), ans.end());

    return ans;
}

// Q3. String formation from substring.
int isRepeat(string s)
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

    int n = s.size();
    if (lps[n - 1] == 0)
        return 0;

    return (n > 0) && (n % (n - lps[n - 1])) == 0 ? 1 : 0;
}

int main() {}