//https://atcoder.jp/contests/dp/tasks/dp_a

#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>

using namespace std;

int dp[1000001];
const int mod = 1e9;
vector<int> H;
int n;

int f(int i)
{
    if (i >= n-1) return 0;
    if(dp[i] != -1) return dp[i];
    return dp[i] = min(abs(H[i] - H[i+1]) + f(i+1), i + 2 >= n ? mod : abs(H[i] - H[i+2]) + f(i+2));
}

int main()
{
    cin >> n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        H.push_back(a);
    }
    cout << f(0);
}