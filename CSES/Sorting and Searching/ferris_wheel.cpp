//https://cses.fi/problemset/task/1090

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n, x, count = 0; cin >> n >> x;
    vector<int> V;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        V.push_back(a);
    }
    sort(V.begin(), V.end());
    int i = 0, j = n - 1;
    while(i <= j)
    {
        int sum = V[i] + V[j];
        if(sum <= x) i++;
        j--;
        count++;
    }
    cout << count;
}