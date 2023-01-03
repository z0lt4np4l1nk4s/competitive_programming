//https://codeforces.com/contest/1760/problem/F

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, d;
        int64_t c;
        cin >> n >> c >> d;
        vector<int> V;
        for(int i = 0; i < n; i++)
        {
            int a; cin >> a;
            V.push_back(a);
        }
        sort(V.begin(), V.end(), greater<int>());
        int64_t s = 0;
        for(int i = 0; i < min(n, d); i++) s += V[i];
        if((int64_t)V[0] * d < c) cout << "Impossible";
        else if(s >= c) cout << "Infinity";
        else
        {
            auto f = [&](int k){
                int64_t r = 0;
                int days = d;
                for(int i = 0; i < min(k + 1, min(n, d)); i++)
                {
                    r += (int64_t)((days + k) / (k + 1)) * V[i];
                    days--;
                }
                return r >= c;
            };

            int l = 0, r = 1;
            while(f(r) == 1) r *= 2;
            while(r - l > 1)
            {
                int m = (l + r) / 2;
                if(f(m) == 1)
                    l = m;
                else
                    r = m;
            }
            cout << l;
        }
        cout << endl;
    }
}