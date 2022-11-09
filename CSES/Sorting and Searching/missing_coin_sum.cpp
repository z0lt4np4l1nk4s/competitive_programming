//https://cses.fi/problemset/task/2183

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
    long long sum = 1;
    for(int i = 0; i < n && sum >= V[i]; i++) sum += V[i];
    cout << sum;
}