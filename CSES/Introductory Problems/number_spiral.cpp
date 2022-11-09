//https://cses.fi/problemset/task/1071

#include <iostream>
 
using namespace std;
 
int main()
{
    int t; cin >> t;
    for(int _ = 0; _ < t; _++)
    {
        long long i, j; cin >> i >> j;
        if(i == j) cout << i * i - (i - 1);
        else if(i > j)
        {
            if(i % 2 == 0) cout << i * i - (j - 1);
            else cout << (i - 1) * (i - 1) + 1 + (j - 1);
        }
        else
        {
            if(j % 2 == 0) cout << (j - 1) * (j - 1) + 1 + (i - 1);
            else cout << j * j - (i - 1);
        }
        cout << endl;
    }
}