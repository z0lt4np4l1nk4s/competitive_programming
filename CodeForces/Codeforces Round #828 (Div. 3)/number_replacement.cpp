//https://codeforces.com/contest/1744/problem/A

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++)
    {
        int n; cin >> n;
        vector<int> A;
        for(int i = 0; i < n; i++)
        {
            int o;
            cin >> o;
            A.push_back(o);
        }
        string s;
        cin >> s;
        vector<int> checked;
        bool b = true;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(A[i] == A[j] && s[i] != s[j]) {b = false; break;}
            }
            if(!b) break;
        }
        cout << (b ? "YES" : "NO") << endl;
    }
}