//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

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
    int k; cin >> k;
    for(int i = 0; i < k; i++)
    {
        int a, b; cin >> a >> b;
        cout << (upper_bound(V.begin(), V.end(), b) - lower_bound(V.begin(), V.end(), a)) << endl;
    }
}