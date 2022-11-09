//https://codeforces.com/contest/1741/problem/A

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string l, r;
        cin >> l >> r;
        if(l == r) cout << '=';
        else if(l[l.size() - 1] == 'S' && r[r.size() - 1] != 'S') cout << '<';
        else if(l[l.size() - 1] != 'S' && r[r.size() - 1] == 'S') cout << '>';
        else if(l[l.size() - 1] == 'L' && r[r.size() - 1] == 'M') cout << '>';
        else if(l[l.size() - 1] == 'M' && r[r.size() - 1] == 'L') cout << '<';
        else if(l[l.size() - 1] == r[r.size() - 1])
        {
            if(l.size() > r.size()) cout << (l[l.size() - 1] == 'S' ? '<' : '>');
            else if(l.size() < r.size()) cout << (l[l.size() - 1] == 'S' ? '>' : '<');
            else cout << '=';
        }
        cout << endl;
    }
    return 0;
}