#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> fun(int n)
{
    if (n == 1)
    {
        vector<string> c(2);
        c[0] = "0";
        c[1] = "1";
        return (c);
    }
    vector<string> prev = fun(n - 1);
    vector<string> z;
    for (int i = 0; i < prev.size(); i++)
    {
        z.push_back('0' + prev[i]);
    }
    for (int j = prev.size() - 1; j >= 0; j--)
    {
        z.push_back('1' + prev[j]);
    }
    return (z);
}

vector<string> generateCode(int N)
{
    return (fun(N));
}

int main() {}