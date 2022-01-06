#include <bits/stdc++.h>
#define fx fixed
#define st setprecision(2)
using namespace std;
int n, q;
double mat[100][100], X[100], e, E[100], x[100];
double eqn1(int i, double x, double y, double z)
{
    if (i == 0)
        return (mat[i][n] - mat[i][1] * y - mat[i][2] * z) / mat[i][i];
    else if (i == 1)
        return (mat[i][n] - mat[i][0] * x - mat[i][2] * z) / mat[i][i];
    else
        return (mat[i][n] - mat[i][0] * x - mat[i][1] * y) / mat[i][i];
}
int main()
{
    cin >> n >> e;
    cout << "Number of functions = " << n << "\nError = " << e << endl;
    cout << "Given Functions:\n5x + 2y + z  = 12\n x + 4y + 2z = 15\n x + 2y + 5z = 20\n";
    cout << "Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cin >> mat[i][j];
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "It. No -  x1\t-  x2\t-  x3\n";
    for (int i = 1;; i++)
    {
        cout << setw(4) << i << "\t";
        for (int j = 0; j < n; j++)
        {
            x[j] = eqn1(j, X[0], X[1], X[2]);
            cout << setw(6) << fx << st << x[j] << "\t";
        }
        for (int j = 0; j < n; j++)
        {
            E[j] = fabs((x[j] - X[j]));
            X[j] = x[j];
        }
        cout << endl;
        if (E[0] < e or E[1] < e or E[2] < e)
            break;
    }
    cout << "\nX1 = " << X[0] << ", X2 = " << X[1] << ", X3 = " << X[2];
    return 0;
}
