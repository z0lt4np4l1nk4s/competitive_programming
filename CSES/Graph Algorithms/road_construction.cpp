//https://cses.fi/problemset/task/1676

#include <iostream>
#include <vector>

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

    void merge(int i, int j){
        int ri = root(i);
        int rj = root(j);
        if(rj != ri){
            sz[rj] += sz[ri];
            V[ri] = rj;
        }
        
    }
};

int main()
{
    int n, m; cin >> n >> m;
    UF uf(n);
    int cnt = n;
    int mxsz = 1;

    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        if(uf.root(a) != uf.root(b))
        {
            uf.merge(a, b);
            cnt--;
            mxsz = max(mxsz, uf.sz[uf.root(a)]);
        }
        cout << cnt << " " << mxsz << endl;
    }
}