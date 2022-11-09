//https://codeforces.com/contest/910/problem/A

#include <iostream>
#include <vector>
#include <string>
#include <queue>
 
using namespace std;
 
int n, d;
int min = 1000;
string s;
int D[200000];
const int inf = 1e9 + 10;
 
void bfs(int i)
{
    for(int j = 0; j < n; j++)
    {
        D[j] = inf;
    }
    D[i] = 0;
    queue<int> Q;
    Q.push(i);
    while(Q.size() > 0)
    {
        i = Q.front();
        Q.pop();
        for(int j = 1; j <= d; j++)
        {
            if(i+j < n && D[i+j] == inf && s[i+j] == '1')    
            {
                D[j+i] = D[i] + 1;
                Q.push(i+j);
            }
        }
    }
}
 
int main()
{
    cin >> n >> d;
    cin >> s;
    bfs(0);
    cout << (D[n-1] == inf ? -1 : D[n-1]); 
}