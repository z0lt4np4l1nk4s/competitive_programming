//https://codeforces.com/contest/1692/problem/D

#include <iostream>
#include <stdio.h>
 
using namespace std;
 
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int sh, sm, d, h, m, c = 0;
        scanf("%d:%d %d", &sh, &sm, &d);
        h = sh; m = sm;
        do
        {
            if(h / 10 == m % 10 && h % 10 == m / 10) c++;
            h += d / 60;
            m += d % 60;
            if(m >= 60) h++;
            m %= 60;
            h %= 24;
        } while(h != sh || m != sm);
        cout << c << endl;
    }
}