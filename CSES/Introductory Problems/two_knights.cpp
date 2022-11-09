//https://cses.fi/problemset/task/1072

#include <iostream>
 
using namespace std;
typedef long long ll;
 
int main()
{
    ll n; cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        ll a = i*i * (i*i - 1) / 2;
        ll b = 4 * (i - 2) * (i - 1);
        cout << (a - b) << endl;
    }
}