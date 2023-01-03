//https://cses.fi/problemset/task/2165

#include <iostream>

using namespace std;

void rec(int src, int dest, int temp, int n)
{
    if(n <= 0) return;
    rec(src, temp, dest, n-1);
    cout << src << " " << dest << endl;
    rec(temp, dest, src, n-1);
}

int main()
{
    int n; cin >> n;
    cout << (1<<n)-1 << endl;
    rec(1, 3, 2, n);
}