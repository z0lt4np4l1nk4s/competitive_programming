//https://cses.fi/problemset/task/2205

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> rec(int n)
{
    vector<string> V;
    if(n == 1)
    {
        V.push_back("0");
        V.push_back("1");
        return V;
    }
    vector<string> prev = rec(n-1);
    for(int i = 0; i < prev.size(); i++)
    {
        string s;
        s += "0";
        s += prev[i];
        V.push_back(s);
    }
    for(int i = prev.size() - 1; i >= 0; i--)
    {
        string s;
        s += "1";
        s += prev[i];
        V.push_back(s);
    }
    return V;
}

int main()
{
    int n; cin >> n;
    for(string s: rec(n)) cout << s << endl;
}