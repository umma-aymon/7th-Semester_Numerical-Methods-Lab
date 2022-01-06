#include <bits/stdc++.h>
#define fx fixed
#define st setprecision(4)
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    cout << "N = " << n << endl;
    double X[n], Y[n], sum_x = 0.0, sum_y = 0.0, sum_xx = 0.0, sum_xy = 0.0, a, b;
    for (auto &el : X)
        cin >> el;
    for (auto &el : Y)
        cin >> el;
    cout << setw(18) << "X - Y - X*X - X*Y\n";
    for (int i = 0; i < n; i++)
    {
        sum_x += X[i];
        sum_y += Y[i];
        sum_xx += X[i] * X[i];
        sum_xy += X[i] * Y[i];
        cout << X[i] << " - " << Y[i] << " - " << sum_xx << "  -  " << sum_xy << endl;
    }
    b = ((n * sum_xy) - (sum_x * sum_y)) / ((n * sum_xx) - (sum_x * sum_x));
    a = (sum_y / n * 1.0) - b * (sum_x / n * 1.0);
    cout << fx << st << "a = " << a << ", b = " << b;
    return 0;
}
