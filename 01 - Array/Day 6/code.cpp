#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Frogs and Jumps.
int unvisitedLeaves(int N, int leaves, int frogs[])
{
    // Code here
    vector<int> jump(leaves + 1, 0);
    int n = 1;
    for (int i = 0; i < N; i++)
    {
        if (frogs[i] <= leaves && jump[frogs[i]] == 0)
        {
            // Mark all the leaves that can be reached by the frog's jump
            for (int j = frogs[i]; j <= leaves; j += frogs[i])
            {
                jump[j] = 1;
            }
        }
    }

    int leafCount = leaves;
    for (int i : jump)
    {
        if (i)
        {
            leafCount--;
        }
    }

    return leafCount;
}

// Q2. Min Subsets with Consecutive Numbers.
int numofsubset(int arr[], int n)
{
    // Your code goes here
    sort(arr, arr + n);
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] > 1)
        {
            count++;
        }
    }

    return count;
}

// Q3. Find Missing And Repeating.
vector<int> findTwoElement(vector<int> arr, int n)
{
    // code here
    vector<int> ans(2);
    for (int i = 0; i < n; i++)
        arr[i]--;

    for (int i = 0; i < n; i++)
        arr[arr[i] % n] += n;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] / n == 2)
            ans[0] = i + 1;
        else if (arr[i] / n == 0)
            ans[1] = i + 1;
    }

    return ans;
}

int main() {}