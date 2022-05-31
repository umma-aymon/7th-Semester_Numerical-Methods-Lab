#include <bits/stdc++.h>
#define fx fixed << setprecision(4)
using namespace std;
double f(double x)
{
    return x * x * x - 2 * x * x + 2 * x + 6;
}
double d(double x)
{
    return 3 * x * x - 4 * x + 2;
}
int main()
{
    double x0, x, e;
    cout << "Given function: f(x) = x^2 - 3x - 2 = 0\n";
    cout << "Derivative of f(x): f`(x) = 2x - 3\n";
    cin >> x0 >> e;
    cout << "Initial value x0: " << x0 << "\nE = " << e << endl;
    x = x0;
    for (int i = 1;; i++)
    {
        x = x0 - (f(x0) / d(x0));
        cout << f(x0) << ", " << d(x0) << " ";
        cout << fx << "x" << i << ": " << x << endl;
        if (abs((x - x0) / x) < e)
            break;
        x0 = x;
    }
    cout << fx << "Root of the equation: " << x << endl;
    return 0;
}
