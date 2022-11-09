//https://codeforces.com/contest/1692/problem/B

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> V;
        for(int i = 0; i < n; i++)
        {
            int a; cin >> a;
            V.push_back(a);
        }
        sort(V.begin(), V.end());
        int c = 0;
        for(int i = 1; i < n; i++)
        {
            if(V[i] == V[i-1]) c++;
        }
        c += c % 2;
        cout << V.size() - c << endl;
    }
}