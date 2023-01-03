//https://cses.fi/problemset/task/1085

#include <iostream>
#include <functional>

using namespace std;
typedef long long ll;

int main()
{
    ll n, k, max = 0; cin >> n >> k;
    vector<ll> V(n);
    for(int i = 0; i < n; i++)
    {
        cin >> V[i];
        if(V[i] > max) max = V[i];
    }
    ll l = max, r = 1e18;
    ll maxSum = 1e18;
    while(l <= r)
    {
        ll m = (l+r) / 2;
        ll c = 1, sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(sum + V[i] > m)
            {
                sum = 0;
                c++;
            }
            sum += V[i];
        }
        if(c > k)
            l = m+1;
        else
        {
            if(m < maxSum) maxSum = m;
            r = m-1;
        }
    }
    cout << maxSum;
}