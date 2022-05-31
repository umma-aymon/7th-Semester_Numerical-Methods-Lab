#include <bits/stdc++.h>
using namespace std;
int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        string number;
        int n;
        cin >> number >> n;

        int dot = number.find('.');      //position of decimal point
        int len = n - dot;               //len of digits before decimal point
        int in = number.find('.') + len; //index to change
        // cout << len << " " << in << endl;
        int x = number[in] - '0';     // n-th digit
        int y = number[in + 1] - '0'; // (n+1)th digit

        if ((y == 5 and x % 2) or (y > 5))
            number[in] = (x + 1) + '0';
        number = number.substr(0, in + 1);
        cout << number << endl;
    }
}
/*
4
3.14159265 3
3.14159265 4
3.14159265 5
3.14159265 8
*/