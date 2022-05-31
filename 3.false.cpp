#include <bits/stdc++.h>
#define fx fixed
#define st setprecision(2)
using namespace std;
double x1, x2, e;
double f(double x)
{
    return x * x - x - 2;
}
void FalsePositionMethod(double x1, double x2)
{
    cout << fx << st << "No -  x1   -  x2   -  x0\n";
    double f1 = f(x1), f2 = f(x2);
    double x0 = x1 - (f1 * (x2 - x1)) / (f2 - f1);
    double tmp_x0 = 0;
    for (int it = 1;; it++)
    {
        cout << it << "  - " << x1 << "  - " << x2 << "  - " << x0 << endl;
        if (abs(x0 - tmp_x0) < e)
            break;
        double f0 = f(x0);
        if (f1 * f0 < 0)
            x2 = x0;
        else
            x1 = x0;
        tmp_x0 = x0;
        f1 = f(x1), f2 = f(x2);
        x0 = x1 - (f1 * (x2 - x1)) / (f2 - f1);
    }
    cout << "Root of the equation: " << x0 << endl;
}
void input()
{
    cin >> x1 >> x2 >> e;
    if (f(x1) * f(x2) > 0)
    {
        cout << "Root does not lie between " << x1 << " and " << x2;
        cout << "\nInput again.\n";
        input();
    }
    else
    {
        cout << "x1 = " << x1 << ", x2 = " << x2 << ", e = " << e << endl;
        FalsePositionMethod(x1, x2);
    }
}
int main()
{

    cout << "Given function: f(x) = x^2 – x – 2 = 0\n";
    input();
    return 0;
}