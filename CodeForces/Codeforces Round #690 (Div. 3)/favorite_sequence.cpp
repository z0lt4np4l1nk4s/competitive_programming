//https://codeforces.com/contest/1462/problem/A

#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    int t; cin >> t;
    for(int _ = 0; _ < t; _++)
    {
        int n; cin >> n;
        vector<int> V;
        vector<int> res;
        for(int i = 0; i < n; i++)
        {
            int a; cin >> a;
            V.push_back(a);
        }
        int i = 0, j = n - 1;
        bool start = true;
        while(i <= j)
        {
            if(start) { res.push_back(V[i]); i++; start = false; }
            else { res.push_back(V[j]); j--; start = true; }
        }
        for(i = 0; i < n; i++) cout << res[i] << " ";
    }
}