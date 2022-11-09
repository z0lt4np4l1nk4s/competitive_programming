//https://codeforces.com/contest/1692/problem/A

#include <iostream>
 
using namespace std;
 
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int a, b, c, d; cin >> a >> b >> c >> d;
        int p = 0;
        if(b > a) p++;
        if(c > a) p++;
        if(d > a) p++;
        cout << p << endl;
    }
}