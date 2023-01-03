//https://atcoder.jp/contests/abc065/tasks/arc076_b

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef long long ll;

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
    int n; cin >> n;
    vector<pair<ll, ll>> P;
    vector<ll> A, B;
    UF uf(n);
    for(int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        P.push_back({a, b});
    }
    for(int i = 0; i < n; i++)
    {
        A.push_back(i);
        B.push_back(i);
    }
    sort(A.begin(), A.end(), [&](int i, int j){
        return P[i].first < P[j].first;    
    });
    sort(B.begin(), B.end(), [&](int i, int j){
        return P[i].second < P[j].second;    
    });
    vector<tuple<ll, ll, ll>> T;
    for(int i = 0; i < n-1; i++)
    {
        T.push_back(
            {
                min(abs(P[A[i]].first -P[A[i+1]].first), abs(P[A[i]].second -P[A[i+1]].second)), 
                A[i], 
                A[i+1]
            });
        T.push_back(
        {
            min(abs(P[B[i]].first -P[B[i+1]].first), abs(P[B[i]].second - P[B[i+1]].second)), 
            B[i], 
            B[i+1]
        });
    }
    sort(T.begin(), T.end());
    ll cost = 0;
    for(int i = 0; i < T.size(); i++)
    {
        auto [a, b, c] = T[i];
        if(uf.merge(b, c))
        {
            cost += a;
        }
    }
    cout << cost;
}