#include <bits/stdc++.h>
#define fx fixed
#define st setprecision(2)
using namespace std;
int n, q;
double mat[100][100], X[100];
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
    cin >> n >> q;
    cout << "Number of functions = " << n << "\nNumber of iteration = " << q << endl;
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
    for (int i = 0; i < q; i++)
    {
        cout << setw(4) << i + 1 << "\t";
        for (int j = 0; j < n; j++)
        {
            X[j] = eqn1(j, X[0], X[1], X[2]);
            cout << setw(6) << fx << st << X[j] << "\t";
        }
        cout << endl;
    }
    cout << "\nX1 = " << X[0] << ", X2 = " << X[1] << ", X3 = " << X[2];
    return 0;
}
