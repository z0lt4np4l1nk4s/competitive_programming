//https://codeforces.com/problemset/problem/1195/B/

#include <iostream>
#include <algorithm>
 
using namespace std;
typedef long long ll;
 
ll count(ll m, ll c)
{
    ll sum = m * (m+1) / 2;
    return sum - c;
}
 
int main()
{
    ll n, k; cin >> n >> k;
 
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
    if(count(l, n-l) == k) cout << n-l;
    else cout << n-r;
}