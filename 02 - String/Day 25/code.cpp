#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Q1. Roman to Integer

// Method 1:
string intToRoman(int A)
{
    string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string romanNumeral = "";

    for (int i = 0; i < 13; i++)
    {
        while (A >= values[i])
        {
            A -= values[i];
            romanNumeral += roman[i];
        }
    }

    return romanNumeral;
}

// Method 2:
// I = 1
// V = 5
// X = 10
// L = 50
// C = 100
// D = 500
// M = 1000

// CM = 900      3DIGITS
// DC = 600
// CD = 400
// XC = 90

// XL = 40      2 DIGITS

// IX = 9       1 DIGIT
// IV =4
string intToRoman(int A)
{

    string str = "";
    while (A > 0)
    {
        if (A >= 1000)
        {
            str = str + "M";
            A -= 1000;
        }
        else if (A >= 900)
        {
            str = str + "CM";
            A -= 900;
        }
        else if (A >= 600)
        {
            str = str + "DC";
            A -= 600;
        }
        else if (A >= 500)
        {
            str = str + "D";
            A -= 500;
        }
        else if (A >= 400)
        {
            str = str + "CD";
            A -= 400;
        }
        else if (A >= 100)
        {
            str = str + "C";
            A -= 100;
        }
        else if (A >= 90)
        {
            str = str + "XC";
            A -= 90;
        }
        else if (A >= 50)
        {
            str = str + "L";
            A -= 50;
        }
        else if (A >= 40)
        {
            str = str + "XL";
            A -= 40;
        }
        else if (A >= 10)
        {
            str = str + "X";
            A -= 10;
        }
        else if (A == 9)
        {
            str = str + "IX";
            A -= 9;
        }
        else if (A >= 5)
        {
            str = str + "V";
            A -= 5;
        }
        else if (A == 4)
        {
            str = str + "IV";
            A -= 4;
        }
        else if (A == 3)
        {
            str = str + "III";
            A -= 3;
        }
        else if (A == 2)
        {
            str = str + "II";
            A -= 3;
        }
        else if (A == 1)
        {
            str = str + "I";
            A -= 3;
        }
    }

    return str;
}

// Method 3:
string intToRoman(int A)
{

    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};

    string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};

    string thns[] = {"", "M", "MM", "MMM"};

    return thns[A / 1000] + hrns[(A % 1000) / 100] + tens[(A % 100) / 10] + ones[A % 10];
}

// Q2. Minimum characters to be added at front to make string palindrome.
int minChar(string str)
{
    // Write your code here
    string temp = "";
    temp += str;
    temp += '$';
    reverse(str.begin(), str.end());
    temp += str;

    vector<int> lps(temp.size(), 0);

    int pre = 0, suf = 1;

    while (suf < temp.size())
    {
        if (temp[pre] == temp[suf])
        {
            lps[suf++] = (pre++) + 1;
        }
        else
        {
            if (pre == 0)
                lps[suf++] = 0;
            else
                pre = lps[pre - 1];
        }
    }

    return str.size() - lps[temp.size() - 1];
}

int main() {}