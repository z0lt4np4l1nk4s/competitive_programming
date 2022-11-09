//https://codeforces.com/contest/1722/problem/A

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
        string s;
        cin >> s;
        if(count(s.begin(), s.end(), 'T') == 1 && count(s.begin(), s.end(), 'i') == 1
        && count(s.begin(), s.end(), 'm') == 1 && count(s.begin(), s.end(), 'u') == 1
        && count(s.begin(), s.end(), 'r') == 1 && s.size() == 5) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}