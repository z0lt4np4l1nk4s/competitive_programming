//https://codeforces.com/contest/1766/problem/A

#include <iostream>
#include <math.h>

using namespace std;

bool is_round(int x)
{
    while (x % 10 == 0)
    {
        x /= 10;
    }
    return x < 10;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int c = 0;
        bool b = false;
        for(int i = 0; i < 6; i++)
        {
            for(int j = 1; j < 10; j++)
            {
                if(pow(10, i) * j > n) 
                {
                    b = true;
                    break;
                }
                c++;
            }
            if(b) break;
        }
        cout << c << endl;
    }
}