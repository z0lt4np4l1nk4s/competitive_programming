//https://codeforces.com/contest/1760/problem/B

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        string s; cin >> s;
        sort(s.begin(), s.end());
        int v = s[n-1];
        cout << v - 96 << endl;
    }
}