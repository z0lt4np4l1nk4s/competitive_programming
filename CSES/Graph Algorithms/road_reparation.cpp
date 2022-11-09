//https://cses.fi/problemset/task/1675

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

struct UF{
    vector<int> V;
    vector<int> sz;
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
        int ri = root(i);
        int rj = root(j);
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
    vector<tuple<int, int, int> > V;
    UF uf(n);
    for(int i = 0; i < m; i++)
    {
        int cost, a, b; cin >> a >> b >> cost;
        a--; b--;
        V.push_back({cost, a, b});
    }
    sort(V.begin(), V.end());
    long long max = 0;
    for(auto [c,a,b]: V)
    {
        if(uf.merge(a,b))
        {
            max += c;
        }
    }
    if(uf.sz[uf.root(0)] != n) cout << "IMPOSSIBLE";
    else cout << max;
}