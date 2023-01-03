//https://codeforces.com/contest/1130/problem/C

#include <iostream>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

int n;
vector<pair<int,int>> S;
vector<pair<int,int>> E;
char arr[50][50];
const int inf = 1e9 + 10;
int D[50][50];

void dfs(bool start, int i, int j)
{
    arr[i][j] = '.';
    for(int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if(!start) cout << x << " " << y << endl;
        if(x < 0 || y < 0 || x >= n || y >= n || arr[x][y] != '0') continue;
        if(start) S.push_back({x+1, y+1});
        else E.push_back({x+1, y+1});
        dfs(start, x, y);
    }
}

int main()
{
    cin >> n;
    int startX, startY; cin >> startX >> startY;
    int endX, endY; cin >> endX >> endY;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int cost = pow(startX-endX, 2) + pow(startY-endY, 2);
    S.push_back({startX, startY});
    E.push_back({endX, endY});
    dfs(true, startX-1, startY-1);
    dfs(false, endX-1, endY-1);
    for(int i = 0; i < S.size(); i++)
    {
        for(int j = 0; j < E.size(); j++)
        {
            int c = pow(S[i].first-E[j].first, 2) + pow(S[i].second-E[j].second, 2);
            if(c < cost) cost = c;
        }
    }
    cout << cost << endl;
}