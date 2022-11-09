//https://cses.fi/problemset/task/1646

#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    int n, q; cin >> n >> q;
    vector<long long> V;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        V.push_back(a + (i == 0 ? 0 : V[i - 1]));
    }
    for(int i = 0; i < q; i++)
    {
        int a, b; cin >> a >> b;
        cout << V[b - 1] -  (a == 1 ? 0 : V[a - 2]) << endl;
    }
}