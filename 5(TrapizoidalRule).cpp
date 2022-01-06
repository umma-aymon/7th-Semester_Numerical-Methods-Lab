#include <bits/stdc++.h>
#define fx fixed
#define st setprecision(3)
using namespace std;
int main()
{
    int n, a, b;
    cin >> a >> b >> n;
    cout << "Given Equation: f(x) = x / (1 + x)\n";
    cout << "Lower Limit: " << a << ", Upper Limit: " << b << ", number of intervals: " << n;
    double h = (b - a) / (n * 1.0);
    double I = 0.0, y[n + 5];
    cout << fx << st << "\n  X\t-\tY=f(x)\n";
    int j = 0;
    for (double i = a; i <= b; i += h)
    {
        double tmp = (i * 1.0) / (1 + i); // Calculating f(x)
        y[j++] = tmp;
        cout << i << "\t" << tmp << endl;
    }
    for (int i = 1; i < n; i++)
        I += y[i]; //Calculating without 1st & last value
    I *= 2;
    I += y[0] + y[n]; //Adding 1st & last value
    cout << "I = " << (h / 2.0) * I << endl;
    return 0;
}