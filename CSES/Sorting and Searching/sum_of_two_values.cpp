//https://cses.fi/problemset/task/1640

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    int n, x; cin >> n >> x;
    vector<pair<int,int>> A;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        A.push_back({a, i+1});
    }
    sort(A.begin(), A.end());
    int i = 0, j = n - 1;
    while(i != j)
    {
        int res = A[i].first + A[j].first;
        if(res == x)
        {
            cout << A[i].second << " " << A[j].second;
            return 0;
        }
        if(res > x) j--;
        else i++;
    }
    cout << "IMPOSSIBLE";
}