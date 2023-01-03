#include <iostream>
#include <string>
#include <set>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> diver;

void check(string m)
{
    set<char> S;
    for(int i = 0; i < m.size(); i++)
    {
        S.insert(m[i]);
    }
    bool v = true;
    for(auto l: S)
    {
        int b = count(m.begin(), m.end(), l);
        if(b > S.size()){
            v = false;
            break;
        }
    }
    if(v) diver.push_back(m);
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        string s; cin >> s;
        int c = 0;
        for(int i = 0; i < n; i++) diver.push_back(s[i]);
        for(int inc = 0; inc < n; inc++)
        {
            string a, b;
            a = s.substr(inc, n - inc);
            b = s.substr(n-inc, inc + 1);
            check(a);
            if(a != b) check(b);
        }
        std::cout << diver.size() << endl;
    }
}