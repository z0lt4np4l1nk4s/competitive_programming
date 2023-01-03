//https://codeforces.com/contest/1760/problem/A

#include <iostream>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int a, b, c; cin >> a >> b >> c;
        if(a > b && a < c || a > c && a < b) cout << a;
        else if(b > a && b < c || b > c && b < a) cout << b;
        else cout << c;
        cout << endl;
    }
}