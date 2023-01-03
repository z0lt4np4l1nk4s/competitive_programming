//https://cses.fi/problemset/task/1633

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll inf = 1000000007;

int main()
{
    int n; cin >> n;
    vector<ll> V(n+1, 0);
    V[0] = V[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= 6; j++)
        {
            if(j > i) break;
            V[i] = (V[i] % inf + V[i-j] % inf) % inf;
        }
    }
    cout << V[n] % inf;
}