//https://cses.fi/problemset/task/1643

#include <iostream>
#include <vector>
 
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
    long long best = -1e18, past = 0;
    for(int i = 0; i < n; i++)
    {
        if(past + V[i] >= V[i]) past += V[i];
        else past = V[i];
        best = max(best, past);
    }
    cout << best;
}