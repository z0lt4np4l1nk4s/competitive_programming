//https://cses.fi/problemset/task/2216

#include <iostream>
#include <vector>
 
using namespace std;
 
int main()
{
    int n; cin >> n;
    vector<int> V;
    vector<int> pos(n);
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        a--;
        V.push_back(a);
        pos[V[i]] = i;
    }
    int c = 1;
    for(int i = 1; i < n; i++)
    {
        if(pos[i] < pos[i-1]) c++;
    }
    cout << c;
}