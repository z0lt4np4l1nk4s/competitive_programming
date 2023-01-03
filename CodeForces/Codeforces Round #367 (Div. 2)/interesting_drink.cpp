//https://codeforces.com/problemset/problem/706/B/

#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
    int n; cin >> n;
    vector<int> V(n);
    for(int i = 0; i < n; i++)
    {
        cin >> V[i];
    }
    sort(V.begin(), V.end());
    int t; cin >> t;
    while(t--)
    {
        int q; cin >> q;
        auto it = upper_bound(V.begin(), V.end(), q);
        int index = it - V.begin();
        cout << index << endl;
    }
}