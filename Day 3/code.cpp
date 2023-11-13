#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Search a 2D Matrix.
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int N = matrix.size(), M = matrix[0].size();
    int start = 0, end = N * M - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int row_index = mid / M;
        int col_index = mid % M;

        if (matrix[row_index][col_index] == target)
            return 1;
        else if (matrix[row_index][col_index] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return 0;
}

// Q2. Find the fine.
long long int totalFine(int n, int date, int car[], int fine[])
{
    long long int totalFine = 0;
    if (date % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (car[i] % 2 != 0)
            {
                totalFine += fine[i];
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (car[i] % 2 == 0)
            {
                totalFine += fine[i];
            }
        }
    }

    return totalFine;
}

// Q3. Greater on right side.
// Function to replace every element with the next greatest element.
void nextGreatest(int arr[], int n)
{
    // code here
    int max = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        int temp = max;
        if (arr[i] > max)
        {
            max = arr[i];
        }
        arr[i] = temp;
    }
}

// Q4. Remove duplicate elements from sorted Array.
int remove_duplicate(int a[], int n)
{
    // code here
    int i = 0, j = 1;
    while (j < n)
    {
        while (a[i] == a[j])
            j++;

        if (j >= n)
            break;

        a[i + 1] = a[j];
        i++;
    }
    return i + 1;
}

int main() {}