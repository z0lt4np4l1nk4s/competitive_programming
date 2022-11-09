//https://cses.fi/problemset/task/1092

#include <iostream>
#include <set>
 
using namespace std;
 
typedef long long ll; 
 
int main()
{
    ll n; cin >> n;
    ll sum = (n * (n+1)) / 2;
    if(sum % 2 == 1) cout << "NO";
    else
    {
        set<ll> s1, s2;
        for(ll i = 1; i <= n; i++) s1.insert(i);
        ll target = sum / 2;
        ll t = n;
        while(s1.count(target) == 0)
        {
            s2.insert(t);
            s1.erase(t);
            target -= t;
            t--;
        }
        s2.insert(target);
        s1.erase(target);
        cout << "YES" << endl;
        cout << s1.size() << endl;
        for(ll i : s1) cout << i << " ";
        cout << endl << s2.size() << endl;
        for(ll i : s2) cout << i << " ";
    }
}