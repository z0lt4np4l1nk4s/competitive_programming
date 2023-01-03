//https://cses.fi/problemset/task/1746

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int mod = 1e9 + 7;
int dp[100001];
int n, m;
int opt[3] = {-1, 0, 1};
vector<int> V;

int f(int i)
{
    if(i == n) return 0;
    if(V[i] != 0) return f(i+1);
    int val1 = V[i-1];
    int val2 = (i+1 >= n ? 0 : V[i+1]);
    if(abs(val1-val2) == 0) return (val1 != m ? 3 : 2) + f(i+1);
    if(abs(val1-val2) == 1) return 2 + f(i+1);
    if(abs(val1-val2) == 2) return 1 + f(i+1);
    return dp[i] = f(i);
}

int main()
{
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        V.push_back(a);
    }
    cout << f(1);
}