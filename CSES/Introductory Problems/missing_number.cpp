//https://cses.fi/problemset/task/1083

#include <iostream>
 
using namespace std;
 
int main()
{
    long long n, sum = 0; cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a; cin >> a;
        sum += a;
    }
    cout << ((n + n * n) / 2 - sum);
}