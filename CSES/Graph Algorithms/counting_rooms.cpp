//https://cses.fi/problemset/task/1192

#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
 
char Grid[1000][1000];
int n, m;
 
void dfs(int i, int j)
{
    Grid[i][j] = '!';
    for(int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
 
        if(x < 0 || y < 0 || x >= n || y >= m || Grid[x][y] != '.') continue;
        dfs(x, y);
    }
}
 
int main()
{
    cin >> n >> m;
    vector<string> V;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin  >> Grid[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(Grid[i][j] == '.'){
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}