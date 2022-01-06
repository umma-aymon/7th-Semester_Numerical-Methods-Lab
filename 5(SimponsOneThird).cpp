#include <bits/stdc++.h>
#define fx fixed
#define st setprecision(3)
using namespace std;
int main()
{
    int n, a, b;
    cin >> a >> b >> n;
    cout << "Given Equation: 1/x\n";
    cout << "Lower Limit: " << a << ", Upper Limit: " << b << ", number of intervals: " << n;
    double h = (b - a) / (n * 1.0);
    double I = 0.0, y[n + 5];
    cout << fx << st << "\n  X\t-\tY=f(x)\n";
    int j = 0;
    for (double i = a; i <= b; i += h)
    {
        if (i == 0) // 1/0 = infinity
            continue;
        double tmp = 1 / i;
        y[j++] = tmp;
        cout << i << "\t" << tmp << endl;
    }
    double odd_sum = 0.0, even_sum = 0.0;
    for (int i = 1; i < n; i++)
    {
        if (i & 1)
            odd_sum += y[i];
        else
            even_sum += y[i];
    }
    I = (2.0 * even_sum) + (4.0 * odd_sum) + y[n];
    cout << "I = " << (h / 3.0) * I << endl;
    return 0;
}