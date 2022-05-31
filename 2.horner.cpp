#include <bits/stdc++.h>
using namespace std;
int main()
{
    /* Input function f(x)=x^3-4x^2+x+2 [my id=2] */
    int n, p, x, n2;
    cin >> n >> p >> x;
    cout << "Number of terms n: " << n << endl;
    cout << "Higest power p: " << p << endl;
    cout << "x: " << x << endl;
    cout << "Coefficients are:\n";
    int a[n];
    n2 = n - 1;
    for (auto &i : a)
    {
        cin >> i;
        cout << "a" << n2-- << ": " << i << "\n";
    }
    int ans = a[0];
    for (int i = 1; i < n; i++)
        ans = ans * x + a[i];
    if (ans)
        cout << "Not satisfied & f(" << x << ") = " << ans;
    else
        cout << "Satisfied & f(" << x << ") = " << ans;
    return 0;
}