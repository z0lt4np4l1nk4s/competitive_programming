//https://codeforces.com/contest/1742/problem/A

#include <iostream>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        if(a + b == c || a + c == b || b + c == a) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}