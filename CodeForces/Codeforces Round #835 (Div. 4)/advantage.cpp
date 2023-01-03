//https://codeforces.com/contest/1760/problem/C

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> V;
        vector<int> S;
        for(int i = 0; i < n; i++)
        {
            int a; cin >> a;
            V.push_back(a);
            S.push_back(a);
        }
        sort(S.begin(), S.end());
        for(int i = 0; i < n; i++)
        {
            auto it = upper_bound(S.begin(), S.end(), V[i]);
            if(it == S.end())
            {
                int index = lower_bound(S.begin(), S.end(), V[i]) - S.begin();
                if(index == n-1) index--;
                cout << V[i] - S[index] << " ";
            }
            else cout << V[i] - S[n-1] << " ";
        }
        cout << endl;
    }
}