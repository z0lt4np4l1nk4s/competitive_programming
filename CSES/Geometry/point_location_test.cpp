//https://cses.fi/problemset/task/2189

#include <iostream>

using namespace std;
typedef long long ll;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        ll x1, x2, x3;
        ll y1, y2, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        ll d = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
        if(d == 0) cout << "TOUCH";
        else if (d < 0) cout << "RIGHT";
        else cout << "LEFT";
        cout << endl;
    }
}