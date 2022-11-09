//https://cses.fi/problemset/result/4815293/

#include <iostream>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    if(n == 1) { cout << "1"; exit(0); }
    if (n < 4) { cout << "NO SOLUTION"; exit(0); }
    bool isEven = n % 2 == 0;
    int a = isEven ? 2 : n - 1;
    bool half = false;
    for(int i = 0; i < n; i++)
    {
        cout << a << " ";
        if(half)
        {
            if(a == n) a = 1;
            else a += 2;
        }
        else
        {
            if (isEven) a += 2;
            else a -= 2;
        }
        if(a == n || a == 0) 
        {
            half = true;
            a = n;
        }
    }
}