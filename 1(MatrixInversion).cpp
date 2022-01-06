#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Given equations: \n";
    cout << "3x + y + 2z = 3\n2x - 3y - z = -3\nx + 2y + z = 4\n";
    int row, col, n;
    cin >> n;
    row = n - 1, col = n - 1;
    int mat[n][n], A[row][col], B[row], At[col][row], cofactor[row][col];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    cout << "Coefficient Matrix A: \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            A[i][j] = mat[i][j];
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Constant Matrix B: \n";
    for (int i = 0; i < row; i++)
    {
        B[i] = mat[i][3];
        cout << B[i] << "\n";
    }

    //finding determinant
    double determinant;
    for (int j = 0; j < col; j++)
        determinant = determinant + (A[0][j] * (A[1][(j + 1) % 3] * A[2][(j + 2) % 3] - A[1][(j + 2) % 3] * A[2][(j + 1) % 3]));
    cout << "Determinant of A: " << determinant << endl;
    if (determinant == 0)
    {
        cout << "Given matrix does not have an inverse\n";
        return 0;
    }



    // transpose matrix
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            At[j][i] = A[i][j];
    cout << "Transpose Matrix At: \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << At[i][j] << " ";
        cout << endl;
    }

    // adjoint matrix
    cout << "Adjoint Matrix Adj(A): \n";
    for (int h = 0; h < row; h++)
    {
        for (int g = 0; g < col; g++)
        {
            cofactor[h][g] = At[(h + 1) % 3][(g + 1) % 3] * At[(h + 2) % 3][(g + 2) % 3] - At[(h + 1) % 3][(g + 2) % 3] * At[(h + 2) % 3][(g + 1) % 3];
            cout << cofactor[h][g] << " ";
        }
        cout << endl;
    }

    // matrix after multiplication
    cout << "Adj(A) * B: \n";
    int X[row];
    for (int i = 0; i < row; i++)
    {
        int x = 0;
        for (int j = 0; j < col; j++)
            x += cofactor[i][j] * B[j];
        X[i] = x;
        cout << X[i] << endl;
    }

    cout << "Matrix X:\n";
    char ch[3] = {'x', 'y', 'z'};
    for (int i = 0; i < 3; i++)
        cout << ch[i] << " = " << (X[i] / determinant) << endl;
    return 0;
}
