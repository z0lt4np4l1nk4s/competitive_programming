//https://codeforces.com/contest/1760/problem/E

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef long long ll;

int n;
vector<int> V;

ll cou()
{
    ll c = 0, z = 0;
    for(int i = 0; i < n; i++)
    {
        if(V[i]) z++;
        else c += z;
    }
    return c;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        cin >> n;
        V.clear();
        for(int i = 0; i < n; i++)
        {
            int a; cin >> a;
            V.push_back(a);
        }
        ll start = cou();
        for(int i = 0; i < n; i++)
        {
            if(V[i] == 0)
            {
                V[i] = 1;
                start = max(start, cou());
                V[i] = 0;
                break;
            }
        }
        for(int i = n-1; i >= 0; i--)
        {
            if(V[i] == 1)
            {
                V[i] = 0;
                start = max(start, cou());
                break;
            }
        }
        cout << start << endl;
    }
}