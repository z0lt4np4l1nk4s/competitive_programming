#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> V;
        vector<int> zc;
        for(int i = 0; i < n; i++)
        {
            int a; cin >> a;
            if(a == 0) zc.push_back(i);
            V.push_back(a);
        }

        cout << count(V.begin(), V.end(), 0) << endl;
    }
}