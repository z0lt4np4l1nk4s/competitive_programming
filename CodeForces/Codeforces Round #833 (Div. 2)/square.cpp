#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        ll n; cin >> n;
        ll res = (n / 2) + (n % 2);
        cout << res << endl;
    }
}