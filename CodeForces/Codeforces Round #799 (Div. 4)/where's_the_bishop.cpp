//https://codeforces.com/contest/1692/problem/C

#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main()
{
    int t; cin >> t;
    while(t--)
    {
        vector<string> V;
        for(int i = 0; i < 8; i++)
        {
            string s; cin >> s;
            V.push_back(s);
        }
        int i = 1, j = 1;
        bool b = false;
        for(; i < 7; i++)
        {
            //i = 3, j == 2
            for(j = 1; j < 7; j++)
            {
                if(V[i][j] == '#' && V[i-1][j-1] == '#' && V[i+1][j+1] == '#' && V[i-1][j+1] == '#' && V[i+1][j-1] == '#') { b = true; break; }
            }
            if(b) break;
        }
        cout << i+1 << " " << j+1 << endl;
    }
}