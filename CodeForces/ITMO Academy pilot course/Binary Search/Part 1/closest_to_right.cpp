//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C

#include <iostream>
#include <vector>

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
    while(k--)
    {
        int a; cin >> a;
        int l = -1, r = n;
        while(r - l > 1)
        {
            int m = (l+r) / 2;
            if(V[m] >= a) r = m;
            else l = m;
        }
        cout << r+1 << endl;
    }
}