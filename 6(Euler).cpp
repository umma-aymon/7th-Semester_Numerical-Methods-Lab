#include <bits/stdc++.h>
using namespace std;
double f(double a, double b)
{
    return 1 - b;
}
int main()
{
    double x0, y0, n, x[100], y[100];
    cin >> x0 >> y0 >> n;
    cout << "Initial value: x = " << x0 << ", y = " << y0 << endl;
    cout << "Tabulated values:\n";
    x[0] = x0, y[0] = y0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        cout << x[i] << " ";
    }
    double h = fabs(x[1] - x[0]);
    cout << "\nx0 = " << x0 << ",   y0 = " << y0 << endl;
    for (int i = 1; i <= n; i++)
    {
        y[i] = y[i - 1] + h * f(x[i - 1], y[i - 1]);
        cout << "x" << i << " = " << x[i] << ", y" << i << " = " << y[i] << endl;
    }
    return 0;
}
