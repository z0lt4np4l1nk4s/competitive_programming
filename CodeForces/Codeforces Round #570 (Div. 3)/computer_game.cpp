//https://codeforces.com/problemset/problem/1183/C/

#include <iostream>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
ll a, b;
 
ll count(ll m, ll c)
{
    return m * a + b * c;
}
 
int main()
{
    int q; cin >> q;
    while(q--)
    {
        ll k, n; cin >> k >> n >> a >> b;
        ll l = 0, r = n;
        while(r-l > 1)
        {
            ll m = (r+l) / 2;
            ll c = count(m, n-m);
            if(c < k)
                l = m;
            else
                r = m;
        }
        if(count(0, n) >= k) cout << -1;
        else if(count(r, n-r) < k) cout << r;
        else cout << l;
        cout << endl;
    }
}