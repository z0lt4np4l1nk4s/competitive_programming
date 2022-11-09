//https://cses.fi/problemset/task/1069

#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
int main()
{
    long c = 1, max = 1;
    string s;
    cin >> s;
    for(long i = 1; i < s.size(); i++)
    {
        if(s[i - 1] == s [i]) c++;
        else c = 1;
        if(c > max) max = c;
    }
    cout << max;
}