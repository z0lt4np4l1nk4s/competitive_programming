//https://cses.fi/problemset/task/1620/
 
#include <iostream>
#include <vector>
#include <functional>
 
using namespace std;
typedef long long ll;
 
ll first_one(ll l, ll r, function<bool(ll)> f) {
  while (r - l > 1) {
    ll m = (l + r) / 2;
    if (f(m) == 0)
      l = m;
    else
      r = m;
  }
 
  return r;
}
 
int main()
{
    int n, t; cin >> n >> t;
    vector<int> V;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        V.push_back(a);
    }
    ll l = 0, r = 1;
    auto f = [&](ll x) {
        ll c = 0;
        for(int i: V)
        {
            c += x / i;
        }
        return c >= t;
    };
    while (f(r) == 0)
        r *= 2;
 
    cout << first_one(l, r, f);
}