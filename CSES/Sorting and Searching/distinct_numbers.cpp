//https://cses.fi/problemset/task/1621

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n; cin >> n;
    vector<int> V;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        V.push_back(a);
    }
    int c = 1;
    sort(V.begin(), V.end());
    for(int i = 1; i < n; i++)
    {
        if(V[i] != V[i - 1]) c++;
    }
    cout << c;
}