//https://cses.fi/problemset/task/1158

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int dp[100001][1000];
vector<int> H;
vector<int> S;
int n;

int f(int x, int i)
{
    if (x == 0) return 1;
    if (i < 0 || i >= n) return 0;
    if(dp[x][i] != -1) return dp[x][i];
    int res = f(x, i+1);
    if (x >= H[i]) res += f(x-H[i], i);
    return dp[x][i] = res;
}

int main()
{
    int x; cin >> n >> x;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        H.push_back(a);
    }
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        S.push_back(a);
    }
    cout << f(x, 0);
}