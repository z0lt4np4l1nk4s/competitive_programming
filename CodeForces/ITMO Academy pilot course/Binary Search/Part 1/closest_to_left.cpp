//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    vector<int> V;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        V.push_back(a);
    }
    for(int i = 0; i < k; i++)
    {
        int a; cin >> a;
        int l = -1, r = n;
        while(r - l > 1)
        {
            int m = (l+r) / 2;
            if(V[m] <= a) l = m;
            else r = m;
        }
        cout << l + 1 << endl;
    }
}