//https://cses.fi/problemset/task/1636

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int mod = 1e9 + 7;
vector<int> coins;
int n;
int dp[1000001][100];

int f(int x, int i)
{
    if (x == 0) return 1;
    if (i < 0 || i >= n) return 0;
    if(dp[x][i] != -1) return dp[x][i];
    int res = f(x, i+1);
    if (x >= coins[i]) res += f(x-coins[i], i);
    res %= mod;
    return dp[x][i] = res;
}

int main()
{
    int x; cin >> n >> x;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        coins.push_back(a);
    }
    cout << f(x, 0);
}