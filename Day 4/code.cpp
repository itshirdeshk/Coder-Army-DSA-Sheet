#include <iostream>
#include <vector>
using namespace std;

// Q1. Subarray with given sum.
vector<int> subarraySum(vector<int> arr, int n, long long s)
{
    // Your code here
    vector<int> ans(1, -1);
    if (s <= 0)
        return ans;

    int i = 0, j = 0;
    int curr_sum = 0;
    while (i <= j)
    {
        if (curr_sum == s)
        {
            ans[0] = i + 1;
            ans.push_back(j);
            return ans;
        }

        else if (curr_sum < s)
        {
            curr_sum += arr[j];
            j++;
        }

        else
        {
            curr_sum -= arr[i];
            i++;
        }

        if (j > n)
            return {-1};
    }

    return {-1};
}

// Q2. Sort an array of 0s, 1s and 2s.
void sort012(int a[], int n)
{
    // code here
    // Dutch National Flag Algorithm
    // This problem is also the same as the famous “Dutch National Flag problem”. The problem was proposed by Edsger Dijkstra. The problem is as follows:
    // Given N balls of colour red, white or blue arranged in a line in random order. You have to arrange all the balls such that the balls with the same colours are adjacent with the order of the balls, with the order of the colours being red, white and blue (i.e., all red coloured balls come first then the white coloured balls and then the blue coloured balls).

    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (a[mid] == 0)
            swap(a[low++], a[mid++]);

        else if (a[mid] == 1)
            mid++;

        else
            swap(a[mid], a[high--]);
    }
}

// Q3. Equilibrium Point.
int equilibriumPoint(long long a[], int n)
{

    // Your code here
    if (n == 1)
        return 1;
    int prefix = 0;
    for (int i = 1; i < n; i++)
    {
        prefix += a[i];
    }

    int curr_sum = 0;

    for (int i = 1; i < n - 1; i++)
    {
        curr_sum += a[i - 1];
        prefix -= a[i];

        if (curr_sum == prefix)
            return i + 1;
    }
    return -1;
}

// Q4. Peak element.
int peakElement(int arr[], int n)
{
    // Your code here
    int start = 0, end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
        {
            return mid;
        }
        else if (arr[mid] >= arr[mid - 1] && arr[mid] <= arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return start;
}

int main() {}