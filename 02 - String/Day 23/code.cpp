#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// Q1. Minimum Days.
int getMinimumDays(int N, string S, vector<int> &P)
{
    // code here
    int day = 0;
    for (int i = 0; i < N; i++)
    {
        if (S[i] != '?' && S[i] == S[i + 1])
        {
            while (S[i] == S[i + 1])
            {
                S[P[day]] = '?';
                day++;
            }
        }
    }
    return day;
}

// Q2. Remove Consecutive Characters.
string solve(string A, int B)
{
    int count = 0, first = 0, second = 0;

    while (first < A.size())
    {
        if (A[first] == A[second])
        {
            count++;
            second++;
        }
        else
        {
            if (count == B)
            {
                A.erase(first, count);
                second -= count;
                first = second;
                count = 0;
            }
            else
            {
                first = second;
                count = 0;
            }
        }
    }
    return A;
}

// Q3. Bulls and Cows.
string solve(string secret, string guess)
{
    // Declare variables to store the number of bulls and cows
    int n = secret.length();
    int cows_ct = 0, bulls_ct = 0;

    // Create an unordered map to count the number of occurrences of each character in the secret string
    unordered_map<char, int> h;

    // Iterate through the secret string
    for (int i = 0; i < n; i++)
    {
        // If the character at the current position is not in the correct position in the guess string, add it to the map
        if (secret[i] != guess[i])
            h[secret[i]]++;
    }

    // Iterate through the guess string
    for (int i = 0; i < n; i++)
    {
        // If the character at the current position is in the correct position in the secret string, increment the bulls counter
        if (guess[i] == secret[i])
            bulls_ct++;
        // Otherwise, if the character is present in the map, increment the cows counter and decrement the count in the map
        else if (h[guess[i]] > 0)
        {
            cows_ct++;
            h[guess[i]]--;
        }
    }

    // Convert the bulls and cows counts to strings and concatenate them to form the final result
    string res = to_string(bulls_ct) + "A" + to_string(cows_ct) + "B";

    // Return the result
    return res;
}
int main() {}