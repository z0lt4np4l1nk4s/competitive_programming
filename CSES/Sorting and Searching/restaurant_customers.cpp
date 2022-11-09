//https://cses.fi/problemset/task/1619

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n; cin >> n;
    vector<pair<int,int> > V;
    for(int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        V.push_back({a, 1});
        V.push_back({b, -1});
    }
    sort(V.begin(), V.end());
    int max = 0;
    int c = 0;
    for(int i = 0; i < V.size(); i++)
    {
        c += V[i].second;
        if(c > max) max = c;
    }
    cout << max;
}