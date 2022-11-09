//https://codeforces.com/contest/1744/problem/C

#include <iostream>
#include <string>
#include <set>
 
using namespace std;
 
int main()
{
    int t = 0; cin >> t;
    for(int _ = 0; _ < t; _++)
    {
        int n; cin >> n;
        char c; cin >> c;
        string s;
        cin >> s;
        set<int> S;
        s += s;
        for(int i = 0; i < 2*n; i++)
        {
            if(s[i] == 'g') S.insert(i);
        }
        int max = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == c)
            {
                auto a = S.lower_bound(i);
                int d = *a;
                if(d - i > max) max = d - i;
            }
        }
        cout << max << endl;
    }
}