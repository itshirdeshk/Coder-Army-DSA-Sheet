#include <iostream>
#include<vector>
using namespace std;

// Q1. Find Transition Point.
int transitionPoint(int arr[], int n)
{
    // code here
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == 1 && arr[mid - 1] == 0)
            return mid;
        else if (arr[mid] == 0)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

// Q2. Alternate positive and negative numbers.
void rearrange(int arr[], int n)
{
    // code here
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            pos.push_back(arr[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            neg.push_back(arr[i]);
        }
    }

    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (x < pos.size() && y < neg.size())
        {
            if (i % 2 == 0)
            {
                arr[i] = pos[x++];
            }
            else
            {
                arr[i] = neg[y++];
            }
        }
        else
        {
            if (x < pos.size())
            {
                arr[i] = pos[x++];
            }
            else if (y < neg.size())
                arr[i] = neg[y++];
        }
    }
}

int main() {}