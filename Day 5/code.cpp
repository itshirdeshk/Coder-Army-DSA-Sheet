#include <iostream>
#include <vector>
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

// Q3. Union of Two Sorted Arrays.
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    // Your code here
    // return vector with correct order of elements
    int i = 0, j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            if (arr1[i] == arr1[i - 1])
            {
                i++, j++;
            }
            else
            {
                ans.push_back(arr1[i]);
                i++, j++;
            }
        }
        else if (arr1[i] < arr2[j])
        {
            if (i == 0)
            {
                ans.push_back(arr1[i++]);
            }
            else if (arr1[i] == arr1[i - 1])
            {
                i++;
            }
            else
            {
                ans.push_back(arr1[i++]);
            }
        }
        else if (arr1[i] > arr2[j])
        {
            if (j == 0)
            {
                ans.push_back(arr2[j++]);
            }
            else if (arr2[j] == arr2[j - 1])
            {
                j++;
            }
            else
            {
                ans.push_back(arr2[j++]);
            }
        }
    }

    if (i < n)
    {
        for (int x = i; x < n; x++)
            if (arr1[x] == arr1[x - 1])
            {
                continue;
            }
            else
                ans.push_back(arr1[x]);
    }
    else
    {
        for (int x = j; x < m; x++)
            if (arr2[x] == arr2[x - 1])
            {
                continue;
            }
            else
                ans.push_back(arr2[x]);
    }

    return ans;
}

// Q4. Three way partitioning.
void threeWayPartition(vector<int> &array, int a, int b)
{
    // code here
    int i = 0, j = 0, k = array.size() - 1;
    while (j <= k)
    {
        if (array[j] < a)
            swap(array[i++], array[j++]);
        else if (array[j] >= a && array[j] <= b)
            j++;
        else
            swap(array[j], array[k--]);
    }
}

int main() {}