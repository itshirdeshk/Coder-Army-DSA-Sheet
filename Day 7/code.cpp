#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

// Q1. Rearrange Array Alternately.
void rearrange(long long *arr, int n)
{

    // Your code here
    int lastidx = n - 1;
    int firstidx = 0;
    int maxi = arr[n - 1] + 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] += (arr[lastidx] % maxi) * maxi;
            lastidx--;
        }
        else
        {
            arr[i] += (arr[firstidx] % maxi) * maxi;
            firstidx++;
        }
    }
    for (int i = 0; i < n; i++)
        arr[i] /= maxi;
}

// Q2. Pythagorean Triplet.
bool checkTriplet(int arr[], int n)
{
    // code here
    vector<bool> a(1001, 0);
    for (int i = 0; i < n; i++)
    {
        a[arr[i]] = true;
    }

    for (int i = 2; i < 1001; i++)
    {
        if (a[i])
            for (int j = i + 1; j < 1001; j++)
            {
                if (a[j])
                {
                    int sum = i * i + j * j;
                    int sqsum = sqrt(sum);
                    int sum1 = sqsum * sqsum;
                    if (sum == sum1 && a[sqsum])
                    {
                        return true;
                    }
                }
            }
    }

    return false;
}

// Q3. Rearrange an array with O(1) extra space.
void arrange(long long arr[], int n)
{
    // Your code here
    for (int i = 0; i < n; i++)
    {
        arr[i] += (arr[arr[i]] % n) * n;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] /= n;
    }
}

// Q4. Count triplets with sum smaller than X.
long long countTriplets(long long arr[], int n, long long sum)
{
    // Your code goes here
    sort(arr, arr + n);
    long long count = 0;
    for (int k = 0; k < n - 2; k++)
    {
        int i = k + 1;
        int j = n - 1;
        while (j > i)
        {
            long long x = arr[i] + arr[j] + arr[k];
            if (x < sum)
            {
                count += (j - i);
                i++;
            }
            else
            {
                j--;
            }
        }
    }
    return count;
}

// Q5. Boolean Matrix.

// Q6. Row with max 1s.
int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    // code here
    int index = -1;
    int count = 0;
    int i = 0, j = m - 1;
    while (i >= 0 && j >= 0 && i < n && j < m)
    {
        if (arr[i][j] == 1)
        {
            int newCount = m - j;
            if (newCount > count)
            {
                count = newCount;
                index = i;
            }
            j--;
        }
        else
        {
            i++;
        }
    }
    return index;
}

int main() {}