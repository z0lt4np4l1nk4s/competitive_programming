//https://codeforces.com/contest/1744/problem/B

#include <iostream>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    int t; cin >> t;
    for(int _ = 0; _ < t; _++)
    {
        int n, q; cin >> n >> q;
        ll evenSum = 0, oddSum = 0;
        ll evenCount = 0, oddCount = 0;
        for(int i = 0; i < n; i++)
        {
            int a; cin >> a;
            if(a % 2 == 0) 
            {
                evenCount++;
                evenSum += a;
            }
            else 
            {
                oddCount++;
                oddSum += a;
            }
        }
        for(int i = 0; i < q; i++)
        {
            int a, b; cin >> a >> b;
            if(a == 0)
            {
                if(b%2==0) 
                {
                    evenSum += b * evenCount;
                }
                else 
                {
                    oddSum += evenSum + b * evenCount;
                    oddCount += evenCount;
                    evenCount = 0;
                    evenSum = 0;
                }
            }
            else
            {
                if(b%2==0) 
                {
                    oddSum += b * oddCount;
                }
                else 
                {
                    evenSum += oddSum + b * oddCount;
                    evenCount += oddCount;
                    oddCount = 0;
                    oddSum = 0;
                }
            }
            cout << oddSum + evenSum << endl;
        }
    }
}