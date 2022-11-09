//https://codeforces.com/contest/1055/problem/B

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

typedef long long ll;

ll l;
int n;

struct UF{
    vector<int> V;
    vector<ll> val;
    vector<pair<int, int>> P;
    unordered_set<int> S;
    UF(int n){
        V.assign(n, 0);
        val.assign(n, 0);
        P.assign(n, {});
        for(int i = 0; i < n; i++)
        {
            V[i] = i;
            S.insert(i);
            P[i] = {i-1, i+1};
        }
    }

    int root(int i)
    {
        if(V[i] == i) return i;
        return V[i] = root(V[i]);
    }

    void merge(int i, int j)
    {
        int ri = root(i);
        int rj = root(j);
        if(ri != rj)
        {
            P[j].first = P[i].first;
            P[i].second = P[j].second;
            S.erase(V[ri]);
            V[ri] = rj;
        }
    }

    int getSeconds()
    {
        int c = 0;
        for (auto i : S) if(val[i] > l) c++; 
        return c;
    }
};

int main()
{
    int m; cin >> n >> m >> l;
    UF uf(n);
    for(int i = 0; i < n; i++)
    {
        ll a; cin >> a;
        uf.val[i] = a;
        if(i > 0 && uf.val[i-1] > l && a > l) 
            uf.merge(i-1, i);
    }
    for(int i = 0; i < m; i++)
    {
        int t; cin >> t;
        if(t)
        {
            ll p, d;
            cin >> p >> d;
            p--;
            uf.val[p] += d;
            if(uf.val[p] > l)
            {
                pair<int,int> P = uf.P[p];
                if(P.second < n && uf.val[P.second] > l) uf.merge(p, P.second);
                if(P.first >= 0 && uf.val[P.first] > l) uf.merge(P.first, p);
            }
        }
        else
        {
            cout << uf.getSeconds() << endl;
        }
    }
}