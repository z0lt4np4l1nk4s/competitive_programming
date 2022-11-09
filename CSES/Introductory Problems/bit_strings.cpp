//https://cses.fi/problemset/task/1617

#include <iostream>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    ll n; cin >> n;
    ll ans = 1;
    for(int i = 0; i < n; i++)
    {
        ans *= 2;
        ans %= (int)(1e9+7);
    }
    cout << ans << endl;
}