//https://cses.fi/problemset/task/1094

#include <iostream>
 
using namespace std;
 
int main()
{
    long long c = 0;
    int n; cin >> n;
    int arr[200000];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 1; i < n; i++)
    {
        if(arr[i] < arr[i - 1]) 
        {
            c += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];             
        }
    }
    cout << c;
}