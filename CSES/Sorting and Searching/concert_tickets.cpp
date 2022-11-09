//https://cses.fi/problemset/task/1091

#include <iostream>
#include <vector>
#include <set>
 
using namespace std;
 
int main()
{
    int n, m; cin >> n >> m;
    vector<int> tickets;
    vector<int> customers;
    set<pair<int,int>> S;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        tickets.push_back(a);
        S.insert({a, i});
    }
    for(int i = 0; i < m; i++)
    {
        int a; cin >> a;
        customers.push_back(a);
    }
    for(int i = 0; i < m; i++)
    {
        auto match = S.lower_bound({customers[i] + 1, 0});
        if(match == S.begin()) cout << -1 << endl;
        else
        {
            match--;
            cout << (*match).first << endl;
            S.erase(match);
        }
    }
}