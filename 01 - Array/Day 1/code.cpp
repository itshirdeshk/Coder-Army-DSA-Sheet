#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Search an Element in an array.
int search(int arr[], int N, int X)
{

    // Your code here
    for (int i = 0; i <= N; i++)
    {
        if (arr[i] == X)
        {
            return i;
        }
    }
    return -1;
}

// Q2. Check if two arrays are equal or not.
bool check(vector<int> A, vector<int> B, int N)
{
    // code here
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = 0; i < N; i++)
    {
        if (A[i] != B[i])
        {
            return 0;
        }
    }

    return 1;
}

// Q3. Missing element of AP.
int findMissing(int arr[], int n)
{
    // code here
    int ans;
    int last = arr[n - 1];
    int first = arr[0];
    int diff = (last - first) / n; // To get the difference between each element in AP

    for (int i = 0; i < n; i++)
    {
        int add = arr[i] + diff;
        if (add != arr[i + 1]) // We are checking if current element+difference should be equal to next element
            return add;        // If its not equal then return the sum of current element and difference
    }
    return -1;
}

// Q4. Cyclically rotate an array by one.
void rotate(int arr[], int n)
{
    int temp = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[0] = temp;
}

int main() {}