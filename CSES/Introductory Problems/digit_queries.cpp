//https://cses.fi/problemset/task/2431

#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

int main()
{
    int q; cin >> q;
    vector<ll> V(19, 1);
    for(int i = 1; i < 19; i++) V[i] = V[i-1] * 10;
    while(q--)
    {
        ll k; cin >> k;
        int numb = 0;
        ll digits = 0, digitsBefore = 0;
        for(int i = 1; i < 19; i++)
        {
            digits += (V[i] - V[i-1])*i;
            if(digits >= k)
            {
                numb = i;
                break;
            }
            digitsBefore += (V[i] - V[i-1])*i;
        }
        ll s = V[numb-1], h = V[numb] - 1;
        ll best = 0, startBest = 0;
        while(s <= h)
        {
            ll m = (s + h) / 2;
            ll pos = digitsBefore + 1 + (m - V[numb-1]) * numb;
            if(pos <= k)
            {
                if(m > best)
                {
                    best = m;
                    startBest = pos;
                }
                s = m + 1;
            }
            else h = m - 1;
        }
        string str = to_string(best);
        cout << str[k-startBest] << endl;
    }
}