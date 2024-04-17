#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

// Q1. Atoi.
int atoi(const string A)
{
    long long int num = 0;
    int n = A.size();
    int j = 0;
    int s = 1; // s represent the sign of number

    // conditions to check if number is positive or negative
    if (A[0] == '-')
    {
        j = 1;
        s = -1;
    }
    if (A[0] == '+')
    {
        j = 1;
        s = 1;
    }

    for (int i = j; i < n; i++)
    {
        if (A[i] == '0' || A[i] == '1' || A[i] == '2' || A[i] == '3' || A[i] == '4' || A[i] == '5' || A[i] == '6' || A[i] == '7' || A[i] == '8' || A[i] == '9')
        {
            num = num * 10 + (A[i] - '0');
        }
        else
        {
            break;
        }
        // checking overflow
        if (num > INT_MAX)
        {
            if (s == 1)
            {
                return INT_MAX;
            }
            else
            {
                return INT_MIN;
            }
        }
    }

    return s * (int)num;
}

// Q2. Valid IP Address.
vector<string> restoreIpAddresses(string A)
{
    vector<string> ans;
    int n = A.size();
    for (int i = 1; i < 4 && i < n - 2; i++)
    {
        for (int j = i + 1; j < i + 4 && j < n - 1; j++)
        {
            for (int k = j + 1; k < j + 4 && k < n; k++)
            {
                string a = A.substr(0, i);
                string b = A.substr(i, j - i);
                string c = A.substr(j, k - j);
                string d = A.substr(k, n - k);
                if (a.size() >= 4 || b.size() >= 4 || c.size() >= 4 || d.size() >= 4)
                    continue;
                if (stoi(a) > 255 || stoi(b) > 255 || stoi(c) > 255 || stoi(d) > 255)
                    continue;
                if ((a[0] == '0' && a.size() > 1) || (b[0] == '0' && b.size() > 1) || (c[0] == '0' && c.size() > 1) || (d[0] == '0' && d.size() > 1))
                    continue;
                ans.push_back(a + "." + b + "." + c + "." + d);
            }
        }
    }
    return ans;
}

int main() {}