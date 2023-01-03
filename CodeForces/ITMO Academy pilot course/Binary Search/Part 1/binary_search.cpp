//https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A

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
    for(int i = 0; i < k; i++)
    {
        int a; cin >> a;
        int l = 0, r = n-1;
        bool found = false;
        while(l <= r && !found)
        {
            int m = (l + r) / 2;
            if(V[m] == a) {
                found = true; break;
            }
            else if(V[m] > a)
            {
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        cout << (found ? "YES" : "NO") << endl;
    }
}