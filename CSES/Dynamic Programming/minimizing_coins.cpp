//https://cses.fi/problemset/task/1634

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> coins;
int C[1000001];
int gres = 1e9;

int dp(int t)
{
    if (t == 0) return 0;
    if(C[t] != -1) return C[t];
    int res = 1e9;
    for(int c: coins)
    {
        if(t >= c)
        {
            res = min(res, 1+dp(t-c));
        }
    }
    return C[t] = res;
}

int main()
{
    int n, t; cin >> n >> t;
    memset(C, -1, sizeof C);
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        coins.push_back(a);
    }
    dp(t);
    if(C[t] == 1e9) cout << -1;
    else cout << C[t];
}