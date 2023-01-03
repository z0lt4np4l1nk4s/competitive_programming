//https://atcoder.jp/contests/abc120/tasks/abc120_d

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

struct UF
{
    vector<int> V;
    vector<ll> size;
    UF(int n){
        V.assign(n, 0);
        size.assign(n, 1);
        for(int i = 0; i < n; i++)
        {
            V[i] = i;
        }
    }

    int root(int i)
    {
        if(V[i] == i) return i;
        return V[i] = root(V[i]);
    }

    ll merge(int i, int j)
    {
        int ri = root(i);
        int rj = root(j);
        if(ri != rj)
        {
            ll res = size[ri] * size[rj];
            size[ri] += size[rj];
            size[rj] = size[ri];
            V[ri] = rj;
            return res;
        }
        return 0;
    }
};

int main()
{
    ll n, m; cin >> n >> m;
    UF uf(n);
    ll f = n * (n - 1) / 2;
    vector<pair<ll, ll>> P;
    for(int i = 0; i < m; i++)
    {
        ll a, b; cin >> a >> b;
        P.push_back({--a, --b});        
    }
    vector<ll> res;
    for(int i = m - 1; i >= 0; i--)
    {
        res.push_back(f);
        f -= uf.merge(P[i].first, P[i].second);
    }
    for(int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << endl;
    }
}