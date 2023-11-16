#include <iostream>
#include <vector>
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

// Q2. 

int main() {}