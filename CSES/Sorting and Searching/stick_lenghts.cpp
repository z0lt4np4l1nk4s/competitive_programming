//https://cses.fi/problemset/task/1074

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
    sort(V.begin(), V.end());
    int center = n / 2;
    long long sum = 0;
    for(int i = 0; i < center; i++)
    {
        sum += abs(V[center] - V[i]);
    }
    for(int i = center + 1; i < n; i++)
    {
        sum += abs(V[center] - V[i]);
    }
    cout << sum;
}