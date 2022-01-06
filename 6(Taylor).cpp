#include <bits/stdc++.h>
using namespace std;
double y[100];
double derivative(double x, double y, int z)
{
    return z == 1 ? x + y : (z == 2 ? 1 + y : y);
}

void taylor(double x, double h, double x0, double y0)
{
    int it = 1;
    while (x - x0 > 0.01)
    {
        int f = 1;
        double y1 = y0, x1;
        y[0] = y0;
        for (int i = 1; i <= 4; i++)
            y[i] = derivative(x0, y[i - 1], i);
        for (int i = 1; i <= 4; i++)
            f *= i, y1 += ((pow(h, i)) / f) * y[i];
        x1 = x0 + h;
        cout << fixed << setprecision(1) << "y" << it++ << " = y(" << x1 << ") = " << setprecision(2) << y1 << endl;
        y0 = y1, x0 = x1;
    }
}

int main()
{
    double x, h, x0, y0;
    cout << "Given equation: dy/dx = x + y\n";
    cin >> x >> h >> x0 >> y0;
    cout << "x = " << x << ", h = " << h << ", x0 = " << x0 << ", y0 = " << y0 << endl;
    cout << "y0 = y(" << x0 << ") =  " << y0 << endl;
    taylor(x, h, x0, y0);
}
