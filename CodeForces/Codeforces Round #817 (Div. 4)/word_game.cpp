//https://codeforces.com/contest/1722/problem/C

#include <iostream>
#include <string>
#include <map>
 
using namespace std;
typedef long long ll;
 
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        map<string, int> M;
        string words[3][1000];
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> words[i][j];
                M[words[i][j]] += 1;
            }
        }
        for(int i = 0; i < 3; i++)
        {
            ll sum = 0;
            for(int j = 0; j < n; j++)
            {
                int value = M[words[i][j]];
                if(value == 2) sum += 1;
                else if(value == 1) sum += 3;
            }
            cout << sum << " ";
        }
        cout << endl;
    }
}