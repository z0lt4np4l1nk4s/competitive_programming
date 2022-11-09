//https://codeforces.com/contest/1133/problem/C

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
    int i = 0, j = 1;
    int c = 0;
 
    while (j < n)
    {
        if(V[j] - V[i] > 5)
        {
            if(j - i > c) c = j - i;
            i++;
        }
        j++;
    }
    if(j - i > c) c = j - i;
    cout << c;
}