//https://cses.fi/problemset/task/1660

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x; cin >> n >> x;
    vector<int> V(n);
    for(int i = 0; i < n; i++)
    {
        cin >> V[i];
    }
    int l = 0, r = 0;
    int sum = V[0];
    int c = 0;
    while(r < n)
    {
        if(sum == x)
        {
            sum -= V[l];
            c++;
            l++;
        }
        else if(sum > x)
        {
            sum -= V[l];
            l++;
        }
        else 
        {
            r++;
            if(r == n) break;
            sum += V[r];
        }
    }
    cout << c;
}