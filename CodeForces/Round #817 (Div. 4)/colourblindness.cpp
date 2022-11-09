//https://codeforces.com/contest/1722/problem/B

#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        string a, b;
        cin >> a;
        cin >> b;
        bool x = false;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == 'R'  && b[i] != 'R' || a[i] != 'R' && b[i] == 'R')
            {
                x = true;
                break;
            }
        }
        cout << (x ? "NO" : "YES") << endl;
    }
}