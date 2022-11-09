//https://codeforces.com/contest/1167/problem/C

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
    for(int i = 0; i < m; i++)
    {
        int k; cin >> k;
        if(k > 0) {
            int a; cin >> a;
            a--;
            for(int j = 0; j < k-1; j++)
            {
                int b; cin >> b;
                b--;
                uf.merge(a, b);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << uf.sz[uf.root(i)] << " ";
    }
}