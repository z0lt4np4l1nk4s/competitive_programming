//https://cses.fi/problemset/task/1629

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
 
using namespace std;
 
bool cmp(pair<int,int> &a, pair<int,int> &b)
{
    return (a.second < b.second);
}
 
int main()
{
    int n; cin >> n;
    vector< pair<int,int> > V;
    for(int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        V.push_back(make_pair(a, b));
    }
    sort(V.begin(), V.end(), cmp);
    int i = 0;
    int last = -1;
    int c = 0;
    while(i < n)
    {
        if(V[i].first >= last)
        {
            last = V[i].second;
            c++;
        }
        i++;
    }
    cout << c;
}