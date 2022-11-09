//https://cses.fi/problemset/task/1084

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n, k, x; cin >> n >> k >> x;
    vector<int> U;
    vector<int> A;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        U.push_back(a);
    }
    for(int i = 0; i < k; i++)
    {
        int a; cin >> a;
        A.push_back(a);
    }
    int i = 0, j = 0, c = 0;
    sort(U.begin(), U.end());
    sort(A.begin(), A.end());
    while(i < n && j < k)
    {
        if(U[i] >= A[j] - x && U[i] <= A[j] + x)
        {
            c++;
            i++;
            j++;
        }
        else if(U[i] - A[j] > x) j++;
        else i++;
    }
    cout << c;
}