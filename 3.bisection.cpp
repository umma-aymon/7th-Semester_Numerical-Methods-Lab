#include <bits/stdc++.h>
#define fx fixed
#define st setprecision(3)
using namespace std;
double x1, x2, e;
double f(double x)
{
    return x * x * x - 2 * x - 2;
}
void bisection_method(double x1, double x2)
{
    int it = 1;
    double x0 = (x1 + x2) / 2.0;
    double f0 = f(x0);
    double f1 = f(x1);
    cout << "No\t- \tx1\t -\tx2\t  -\t x0\t   -  f0\n";
    cout << fx << st << it++ << "\t- " << x1 << "  - " << x2 << "  - " << x0 << "  - " << f0 << endl;
    while (abs((x2 - x1) / x2) >= e)
    {
        if (f1 * f0 < 0)
            x2 = x0;
        else
            x1 = x0;
        x0 = (x1 + x2) / 2.0;
        f0 = f(x0);
        f1 = f(x1);
        cout << it++ << "\t- " << x1 << "  - " << x2 << "  - " << x0 << "  - " << f0 << endl;
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
        bisection_method(x1, x2);
    }
}
int main()
{
    input();
    return 0;
}