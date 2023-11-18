#include <iostream>
#include <vector>
#include<algorithm>
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

// Q5. 

int main() {}