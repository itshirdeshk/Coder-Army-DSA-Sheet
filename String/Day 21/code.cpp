#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

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

// Q2. Case-specific Sorting of Strings.
string caseSort(string str, int n)
{
    // your code here
    vector<int> lower(26, 0);
    vector<int> upper(26, 0);

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            upper[str[i] - 'A']++;
        }
        else
        {
            lower[str[i] - 'a']++;
        }
    }

    string lower_string, upper_string;

    for (int i = 0; i < 26; i++)
    {
        while (lower[i])
        {
            lower_string += 'a' + i;
            lower[i]--;
        }
        while (upper[i])
        {
            upper_string += 'A' + i;
            upper[i]--;
        }
    }

    int first = 0, second = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = upper_string[second++];
        }
        else
        {
            str[i] = lower_string[first++];
        }
    }

    return str;
}

// Q3. Excel Sheet | Part - 1.
string ExcelColumn(int N)
{
    // Your code goes here
    string ans;
    while (N)
    {
        char c = 'A' + (N % 26 == 0 ? 25 : N % 26 - 1);
        if (N % 26 == 0)
        {
            N = (N / 26) - 1;
        }
        else
            N = N / 26;
        ans = c + ans;
    }
    return ans;
}

int main() {}
