//https://codeforces.com/contest/1766/problem/B

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, c = 0; cin >> n;
        vector<int> V(26*26);
        vector<int> S(26*26);
        V.assign({0});
        S.assign({0});
        string s; cin >> s;
        bool b = false;
        for(int i = 1; i < n; i++)
        {
            int val = ((s[i-1] - 'a')*26 + s[i] - 'a');
            if(V[val] != 0) 
            {
                if(i - S[val] >= 2)
                {
                    b = true;
                    break;
                }
            }
            else 
            {
                S[val] = i;
                V[val] = 1;
            }
        }
        if (b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}