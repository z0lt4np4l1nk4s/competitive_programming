//https://atcoder.jp/contests/abc146/tasks/abc146_c

#include <iostream>
#include <functional>
 
using namespace std;
typedef unsigned long long ll;
 
ll a, b, x;
 
ll digits(ll n)
{
    int c = 0;
    while(n != 0)
    {
        c++;
        n /= 10;
    }
    return c;
}
 
ll cost(ll n)
{
    return a * n + b * digits(n);
}
 
int main()
{
    cin >> a >> b >> x;
    ll r = 1;
    while(cost(r) < x)
        r *= 2;
 
    ll l = 0;
    while(r-l > 1)
    {
        ll m = (l+r) / 2;
        if(cost(m) > x)
            r = m;
        else
            l = m;
    }
    if(cost(l) <= x)
        cout << l;
    else 
        cout << r;
}