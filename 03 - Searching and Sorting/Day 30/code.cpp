#include <iostream>
#include<vector>
using namespace std;

// Q1. Bubble Sort.
void bubbleSort(int arr[], int n)
{
    // Your code here
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Q2. Insertion Sort.
void insertionSort(int arr[], int n)
{
    // code here
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

// Q3. First and last occurrences of X.
vector<int> firstAndLast(vector<int> &arr, int n, int x)
{
    // Code here
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            if ((i != 0 && arr[i - 1] != x) || i == 0)
            {
                ans.push_back(i);
            }

            if ((i != n - 1 && arr[i + 1] != x) || i == n - 1)
            {
                ans.push_back(i);
            }
        }
    }

    if (ans.size() == 0)
    {
        ans.push_back(-1);
    }

    return ans;
}

int main() {}