//https://codeforces.com/contest/1722/problem/D

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<pair<int, char> > V;
        ll sum = 0;
        string s; cin >> s;
        for(int i = 0; i < n; i++)
        {
            int value = 0;
            if(s[i] == 'L') value = i;
            else value = n - i - 1;
            sum += value;
            V.push_back({value, s[i]});
        }
        sort(V.begin(), V.end());
        for(int i = 0; i < n; i++)
        {
            int value = 0;
            value = n - V[i].first - 1;
            if(sum + value - V[i].first > sum)
            {
                sum += value - V[i].first;
            }
            cout << sum << " ";
        }
        cout << endl;
    }
}