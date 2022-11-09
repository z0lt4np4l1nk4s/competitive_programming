//https://codeforces.com/contest/1747/problem/B

#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        string s = "";
        vector<pair<int, int> > V;
        for(int i = 0; i < n; i++)
        {
            s += "BAN";
        }
        int i = 1, j = 3*n - 1; 
        while(s.find("BAN") != string::npos && i <= j)
        {
            if(i != j) V.push_back({i, j});
            i+=3;
            j-=3;
        }
        cout << V.size() << endl;
        for(int i = 0; i < V.size(); i++) cout << V[i].first+1 << " " << V[i].second+1 << endl;
    }
}