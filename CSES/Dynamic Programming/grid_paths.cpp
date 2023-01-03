//https://cses.fi/problemset/task/1638

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

const int mod = 1e9 + 7;
int dp[1000][1000];
vector<string> S;
int n;

int f(int x, int y)
{
    if (x == n || y == n || S[x][y] == '*') return 0;
    if(x == n-1 && y == n-1) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    int val = 0;
    return dp[x][y] = (val + f(x+1, y) + f(x, y+1)) % mod;
}

int main()
{
    cin >> n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
    {
        string s; cin >> s;
        S.push_back(s);
    }
    cout << f(0, 0);
}