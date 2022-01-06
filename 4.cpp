#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, x;
    cin >> n >> x;
    cout << "n = " << n << ", x = " << x << endl;
    double X[n + 1], diffY[n + 1], Y[n + 1][n + 1];
    for (int i = 0, j = 0; i < n; i++)
        cin >> X[i] >> Y[j][i];

    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            Y[i][j] = Y[i - 1][j + 1] - Y[i - 1][j];
    cout << "X\t   Y\t  d1    d2     d3    d4    d5\n";

    for (int i = 0; i < n; i++)
    {
        cout << X[i] << "\t";
        for (int j = 0; j < n - i; j++)
            cout << setw(4) << Y[j][i] << "\t";
        cout << endl;
    }
    double h = X[1] - X[0];
    double s = (x - X[0]) / h;
    cout << "u = " << s << endl;
    for (int i = 1; i < 10; i++)
    {
        if (i < n)
            diffY[i] = Y[i][0];
        else
            diffY[i] = 0;
    }
    double f1 = 1 / h * (diffY[1] + 1 / 2.0 * (2 * s - 1) * diffY[2] + 1 / (6.0) * (3 * s * s - 6 * s + 2) * diffY[3] + 1 / (24.0) * (4 * s * s * s - 18 * s * s + 22 * s - 6) * diffY[4]);
    double f2 = 1 / (h * h) * (diffY[2] + 1 / 6.0 * (6 * s - 6) * diffY[3] + 1 / 24.0 * (12 * s * s - 36 * s + 22) * diffY[4]);
    cout << "dy/dx = " << f1 << "\nd2y/dx2 = " << f2 << endl;

    return 0;
}