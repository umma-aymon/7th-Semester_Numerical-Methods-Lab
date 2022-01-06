#include <bits/stdc++.h>
using namespace std;
double f(double a, double b)
{
    return 1 - b;
}
int main()
{
    double x, y, h = 0.1, xp, m1, xx[4] = {0};
    cin >> x >> y >> xx[1] >> xx[2] >> xx[3];
    cout << "Initial values of x and y: " << x << ", " << y << endl;
    cout << "Values of X = " << xx[1] << ", " << xx[2] << ", " << xx[3] << endl;
    cout << "h = " << h << endl;
    cout << fixed << setprecision(3) << "i -\t x \t-\t y\n";
    for (int i = 1; i <= 3; i++)
    {
        m1 = f(xx[i], y);
        y += h * m1;
        cout << i << "\t" << xx[i] << "\t" << y << endl;
    }
    return 0;
}
