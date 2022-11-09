//https://codeforces.com/contest/279/problem/B

#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n, t; cin >> n >> t;
    vector<int> V;
    for(int i = 0; i < n; i++)
    {
        int a; cin >> a;
        V.push_back(a);
    }
    int i = 0, j = 0;
    int c = 0;
    int sum = 0;
    while(i < n)
    {
        while(j < n && sum + V[j] <= t)
        {
            sum += V[j];
            j++;
        }
        if(j -i > c) c= j-i;
        sum -= V[i];
        i++;
    }
    cout << c;
}