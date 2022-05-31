#include <bits/stdc++.h>
#define fx fixed << setprecision(4)
using namespace std;
double f(double x)
{
    return 1 / sqrt(x + 1);
}
int main()
{
    double x0, x, e;
    cout << "Given function: f(x) = x^3 - x^2 - 1 = 0\n";
    cout << "Given function can be written as: x = g(x) = 1/sqrt(x+1)\n";
    cin >> x0 >> e;
    cout << "Initial value x0: " << x0 << "\nE = " << e << endl;
    for (int i = 1;; i++)
    {
        x = f(x0);
        cout << fx << "x" << i << ": " << x << endl;
        if (abs((x - x0) / x) < e)
            break;
        x0 = x;
    }
    cout << "Root of the equation: " << x0 << endl;
    return 0;
}
