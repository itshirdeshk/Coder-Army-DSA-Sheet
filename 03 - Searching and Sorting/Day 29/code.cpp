#include <iostream>
#include <unordered_map>
using namespace std;

// Q1. Searching an element in a sorted array.
int searchInSorted(int arr[], int N, int K)
{

    // Your code here
    int start = 0, last = N - 1;
    int mid;
    while (start <= last)
    {
        mid = start + (last - start) / 2;
        if (arr[mid] == K)
            return 1;
        else if (arr[mid] < K)
            start = mid + 1;
        else
            last = mid - 1;
    }
    return -1;
}

// Q2. Last index of One.
int lastIndex(string s)
{
    int index = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
            index = i;
    }

    return index;
}

// Q3. Count the Zeros.
int countZeroes(int arr[], int n)
{
    // code here
    int index, start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == 0)
        {
            index = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return n - index;
}

// Q4. Elements in the Range
bool check_elements(int arr[], int n, int A, int B)
{
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        visited[arr[i]] = true;
    }
    for (int i = A; i <= B; i++)
    {
        if (!visited[i])
            return (false);
    }
    return (true);
}

int main() {}