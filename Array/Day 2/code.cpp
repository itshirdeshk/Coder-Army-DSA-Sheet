#include <iostream>
using namespace std;

// Q1. Find minimum and maximum element in an array.
pair<long long, long long> getMinMax(long long a[], int n)
{

    long long max = a[0], min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];

        if (a[i] < min)
            min = a[i];
    }
    return {min, max};
}

// Q2. Binary Array Sorting.
void binSort(int A[], int N)
{
    int start = 0, end = N - 1;
    while (start < end)
    {
        if (A[start] == 1 && A[end] == 0)
        {
            swap(A[start], A[end]);
            start++, end--;
        }
        else if (A[start] == 0 && A[end] == 0)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
}

// Q3. Move all negative elements to end.
void segregateElements(int arr[], int n)
{
    // Your code goes here
    int newArr[n];
    int loc = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            newArr[loc] = arr[i];
            loc++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            newArr[loc] = arr[i];
            loc++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = newArr[i];
    }
}

// Q4. Missing number.
int missingNumber(int A[], int N)
{
    // Your code goes here
    int realSum = (N * (N + 1)) / 2;

    int sum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        sum += A[i];
    }

    return realSum - sum;
}

int main() {}