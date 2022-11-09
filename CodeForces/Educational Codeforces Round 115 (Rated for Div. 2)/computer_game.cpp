//https://codeforces.com/contest/1598/problem/A

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
 
using namespace std;
 
int n;
const int dx[6] = {0,1,0,-1,1,-1};
const int dy[6] = {1,0,-1,0,1,1};
 
 
int visited[2][100];
vector<string> V;
 
int dfs(int i, int j)
{
    visited[i][j] = -1; 
    for(int k = 0; k < 6; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if(x < 0 || y < 0 || x >= 2 || y >= n || visited[x][y] == -1 || V[x][y] != '0') continue;
        if(x == 1 && y == n-1) return true;
        bool b = dfs(x, y);
        if(b) return true;
    }
    return false;
}
 
int main()
{
    int t; cin >> t;
    while(t--)
    {
        V.clear();
        memset(visited, 0, sizeof visited);
        cin >> n;
        for(int i = 0; i < 2; i++)
        {
            string s; cin >> s;
            V.push_back(s);
        }
        cout << (dfs(0,0) ? "YES" : "NO") << endl;
    }
}