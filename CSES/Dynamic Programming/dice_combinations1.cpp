//https://cses.fi/problemset/task/1633

#include <iostream>

using namespace std;

const int mod = 1e9+7;
int dp[1000001];

int f(int n)
{
    if (n < 0) return 0;
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int res = f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5) + f(n-6);
}

int main()
{
    int n; cin >> n;
    memset(dp, -1, sizeof dp);
        // fill(dp, dp+n, -1);
    cout << f(n);
}