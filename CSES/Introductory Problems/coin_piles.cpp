//https://cses.fi/problemset/task/1754

#include <iostream>
 
using namespace std;
 
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int a, b; cin >> a >> b;
        if(max(a,b) > 2 * min(a, b) || (a + b) % 3 != 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}