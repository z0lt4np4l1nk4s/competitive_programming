//https://codeforces.com/contest/1742/problem/B

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int t; cin >> t;
    bool anyDuplicate;
    for(int i = 0; i < t; i++)
    {
        int n, a; cin >> n;
        anyDuplicate = false;
        vector<int> A;
        for(int j = 0; j < n; j++)
        {
            cin >> a;
            A.push_back(a);
        }
        sort(A.begin(), A.end());
        int prev = A[0];
        for(int i = 1; i < A.size(); i++)
        {
            if(A[i] == prev){
                anyDuplicate = true;
                break;
            }
            prev = A[i];
        }
        cout << (!anyDuplicate ? "YES" : "NO") << endl;
    }
}