#include <bits/stdc++.h>
#define fx fixed << setprecision(4)
using namespace std;
int n, x_r;
vector<int> a, b;
void function_print(string s, vector<int> v)
{
    cout << "Function " << s << ": ";
    int n2 = n;
    for (int i = 0; i <= n; i++)
    {
        if (v[i] == 0)
        {
            n2--;
            continue;
        }
        if (v[i] > 0 and i != 0)
            cout << "+ " << v[i] << "x^" << n2-- << " ";
        else
            cout << v[i] << "x^" << n2-- << " ";
    }
    cout << endl;
}
void coefficients_print(string s, vector<int> &v)
{
    cout << "Coefficients of " << s << ": ";
    for (auto el : v)
        cout << el << " ";
    cout << endl;
}
int main()
{
    cin >> n >> x_r;
    a.resize(n + 1);
    b.resize(n + 1);
    for (auto &el : a)
        cin >> el;
    cout << "Number of terms = " << n << ", Root = " << x_r << endl;
    function_print("p(x)", a);
    reverse(a.begin(), a.end());
    coefficients_print("p(x)", a);
    for (int i = n; i > 0; i--)
        b[i - 1] = a[i] + (x_r * b[i]);
    coefficients_print("q(x)", b);
    reverse(b.begin(), b.end());
    function_print("q(x)", b);
    return 0;
}
