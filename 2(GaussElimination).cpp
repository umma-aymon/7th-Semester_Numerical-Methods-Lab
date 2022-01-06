#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, k;
    cin >> n;
    cout << "Number of unknowns: " << n << endl;
    double mat[n][n + 1];
    cout << "Augmented Matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            cin >> mat[i][j];
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    /* Applying Gauss Elimination */
    for (i = 0; i < n - 1; i++)
    {
        if (mat[i][i] == 0.0)
        {
            cout << "Mathematical Error!\n";
            exit(0);
        }
        for (j = i + 1; j <= n - 1; j++)
        {
            double x = (mat[j][i] / mat[i][i]) * -1;
            for (k = 0; k <= n; k++)
                mat[j][k] += x * mat[i][k];
        }
    }
    cout << "Triangular Matrix:\n";
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n + 1; j++)
        {
            int x = mat[i][j];
            int y = (mat[i][j] - x) * 10;
            // cout << x << " " << y << " ";
            if (y > 0)
            {
                int numr = x * pow(10, 1) + y;
                int deno = pow(10, 1);
                int gd = __gcd(numr, deno);
                cout << setw(2) << numr / gd << "/" << deno / gd << " ";
            }
            else if (j == n)
                cout << setw(2) << " = " << mat[i][j] << " ";
            else
                cout << setw(4) << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Obtaining Solution by Back Subsitution:\n";
    double X[n];
    X[n - 1] = mat[n - 1][n] / mat[n - 1][n - 1];
    for (i = n - 1; i >= 0; i--)
    {
        X[i] = mat[i][n];
        for (j = i + 1; j < n; j++)
            X[i] -= mat[i][j] * X[j];
        X[i] /= mat[i][i];
    }
    string s = "XYZ";
    for (int i = 0; i < n; i++)
        cout << s[i] << " = " << X[i] << endl;
    return (0);
}
