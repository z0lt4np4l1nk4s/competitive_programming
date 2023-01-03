//https://cses.fi/problemset/task/1623

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
    int n; cin >> n;
    vector<int> V;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        V.push_back(a);
    }
    ll ans = 1e18;
    for(int i = 0; i < (1<<n); i++)
    {
        ll sum1 = 0, sum2 = 0;
        for(int pos = 0; pos < n; pos++)
        {
            if(i&(1<<pos)) sum1 += V[pos];
            else sum2 += V[pos];
        }
        ans = min(ans, abs(sum1 - sum2));
    }
    cout << ans;
}