//https://cses.fi/problemset/task/1637

#include <iostream>
#include <cstring>

using namespace std;

int dp[1000001];

int f(int n)
{
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int number = n, m = 0;
    while (number > 0) 
    {
        m = max(m, number % 10);
        number /= 10;
    }
    return dp[n] = 1 + f(n - m);
}

int main()
{
    int n; cin >> n;
    memset(dp, -1, sizeof dp);
    cout << f(n);
}