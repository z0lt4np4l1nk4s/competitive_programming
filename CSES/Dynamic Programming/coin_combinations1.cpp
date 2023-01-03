//https://cses.fi/problemset/task/1635

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int mod = 1e9 + 7;
vector<int> coins;
int dp[1000001];

int f(int n)
{
    if (n < 0) return 0;
    if (n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    int res = 0;
    for(int c: coins)
    {
        if(c <= n)
        {
            res += f(n-c);
            res %= mod;
        }
    }
    return dp[n] = res;
}

int main()
{
    int n, x; cin >> n >> x;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        coins.push_back(a);
    }
    cout << f(x);
}