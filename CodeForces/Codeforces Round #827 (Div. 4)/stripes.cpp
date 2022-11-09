//https://codeforces.com/contest/1742/problem/C

#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
int main()
{
    int t, n = 8;
    cin >> t;
    for(int _ = 0; _ < t; _++)
    {
        char c = 'B';
        vector<string> A;
        bool found = false;
        for(int i = 0; i < 8; i++)
        {
            string s;
            cin >> s;
            A.push_back(s);
            int a = 0;
            if(!found)
            {
                for(int k = 0; k < n; k++) 
                {
                    if('R' != s[k]) break;
                    else a++;
                }
            }
            if(a == n) 
            {
                c = 'R';
                found = true;
            }
        }
        if(!found)
        {
            for(int i = 0; i < n; i++)
            {
                int a = 0;
                for(int j = 0; j < n; j++)
                {
                    if(A[j][i] != 'B') break;
                    else a++;
                }
                if(a == n)
                {
                    c = 'B';
                    break;
                }
            }
        }
        cout << c << endl;
    }
}