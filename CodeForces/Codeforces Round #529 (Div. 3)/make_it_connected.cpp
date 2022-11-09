//https://codeforces.com/contest/1095/problem/F
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
 
using namespace std;
 
typedef long long ll;
 
struct UF{
    vector<ll> V;
    vector<ll> sz;
    UF(int n){
        V.assign(n, 0);
        sz.assign(n, 1);
        for(int i = 0; i < n; i++)
        {
            V[i] = i;
        }
    }
 
    int root(int i){
        if(V[i] == i) return i;
        return V[i] = root(V[i]);
    }
 
    bool merge(int i, int j){
        ll ri = root(i);
        ll rj = root(j);
        if(rj != ri){
            sz[rj] += sz[ri];
            V[ri] = rj;
            return true;
        }
        return false;
    }
};
 
int main()
{
    int n, m; cin >> n >> m;
    vector<tuple<ll,ll,ll>> V;
    vector<pair<ll,ll>> edges;
    UF uf(n);
    for(int i = 0; i < n; i++)
    {
        ll a; cin >> a;
        edges.push_back({a, i});
    }
    sort(edges.begin(), edges.end());
    for(int i = 1; i < n; i++)
    {
        V.push_back({edges[0].first + edges[i].first, edges[0].second, edges[i].second});
    }
    for(int i = 0; i < m; i++)
    {
        ll z, y, w; cin >> z >> y >> w;
        z--; y--;
        V.push_back({w, z, y});
    }
    sort(V.begin(), V.end());
    ll cost = 0;
    for(int i = 0; i < V.size(); i++)
    {
        auto [a, b, c] = V[i];
        if(uf.merge(b, c)) cost += a;
    }
    cout << cost;
}