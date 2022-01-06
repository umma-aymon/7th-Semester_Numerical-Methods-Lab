#include <bits/stdc++.h>
using namespace std;
double f(double a, double b)
{
    return 3.0 * a + 2.0 * b;
}
int main()
{
    double x, y, h, xp, m1, m2, m3, m4;
    cin >> x >> y >> xp >> h;
    cout << "Initial values of x and y: " << x << ", " << y << endl;
    cout << "XP = " << xp << ", h = " << h << endl;
    int n = (xp - x) / h + 0.5;
    cout << fixed << setprecision(2) << setw(10) << "i -\t x \t-\ty\n";
    for (int i = 1; i <= n; i++)
    {
        m1 = f(x, y);
        m2 = f(x + 0.5 * h, y + 0.5 * m1 * h);
        m3 = f(x + 0.5 * h, y + 0.5 * m2 * h);
        m4 = f(x + h, y + m3 * h);
        x += h;
        y += (m1 + 2.0 * m2 + 2.0 * m3 + m4) * h / 6.0;
        cout << i << "\t" << x << "\t" << y << endl;
    }
    cout << "\nValue of y at x = " << x << " is " << y;
    return 0;
}
