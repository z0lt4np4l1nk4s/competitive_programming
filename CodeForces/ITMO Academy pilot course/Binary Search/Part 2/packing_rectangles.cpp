//https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A

#include <iostream>
#include <functional>

using namespace std;
typedef long long ll;

ll first_one(ll l, ll r, function<bool(ll)> f)
{
    while(r - l > 1)
    {
        ll m = (l+r) / 2;
        if(f(m) == 0) l = m;
        else r = m;
    }
    return r;
}

int main()
{
    ll w, h, n; cin >> w >> h >> n;
    auto f = [&](ll b) {
        return (b / w) * (b / h) >= n;
    };
    ll r = 1;
    while(f(r) == 0) r *= 2;
    cout << first_one(0, r, f);
}