#include <bits/stdc++.h>
#define fx fixed
#define st setprecision(2)
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, d;
    cin >> n >> d;
    cout << "N = " << n << ", Degree = " << d << endl;
    double x, y, sum_x = 0.0, sum_y = 0.0, sum_xx = 0.0, sum_xxx = 0, sum_xxxx = 0, sum_xy = 0.0, sum_xxy, a[4];
    cout << fx << st << setw(50) << "X \t - \t Y \t-\t X*X - X*X*X - X*X*X*X - X*Y - X*X*Y\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        sum_x += x;
        sum_y += y;
        sum_xx += x * x;
        sum_xxx += x * x * x;
        sum_xxxx += x * x * x * x;
        sum_xy += x * y;
        sum_xxy += x * x * y;
        cout << x << " - " << y << " - " << sum_xx << " - " << sum_xxx << "  -  " << sum_xxxx << "  - " << sum_xy << " - " << sum_xxy << endl;
    }
    a[0] = n * (sum_xx * sum_xxxx - sum_xxx * sum_xxx) - sum_x * (sum_x * sum_xxxx - sum_xx * sum_xxx) + sum_xx * (sum_x * sum_xxx - sum_xx * sum_xx);
    a[1] = sum_y * (sum_xx * sum_xxxx - sum_xxx * sum_xxx) - sum_x * (sum_xy * sum_xxxx - sum_xxy * sum_xxx) + sum_xx * (sum_xy * sum_xxx - sum_xx * sum_xxy);
    a[2] = n * (sum_xy * sum_xxxx - sum_xxx * sum_xxy) - sum_y * (sum_x * sum_xxxx - sum_xx * sum_xxx) + sum_xx * (sum_x * sum_xxy - sum_xx * sum_xy);
    a[3] = n * (sum_xx * sum_xxy - sum_xxx * sum_xy) - sum_x * (sum_x * sum_xxy - sum_xx * sum_xy) + sum_y * (sum_x * sum_xxx - sum_xx * sum_xx);
    cout << fx << st << "a0 = " << a[1] / a[0] << ", a1 = " << a[2] / a[0] << ", a2 = " << a[3] / a[0];
    return 0;
}
