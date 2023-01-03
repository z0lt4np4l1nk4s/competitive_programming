//https://cses.fi/problemset/task/1624

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, int>> V;
vector<string> Grid;
int c = 0;

bool check(int x, int y)
{
    for(pair<int, int> P : V)
    {
        if(y == P.second) return false;
        if(x - P.first == abs(y - P.second)) return false;
    }
    return true;
}

void rec(int x)
{
    if(V.size() == 8) 
    {
        c++;
        return;
    }
    for(int i = 0; i < 8; i++)
    {
        if(Grid[x][i] == '*' || !check(x, i)) continue;
        V.push_back({x, i});
        rec(x+1);
        V.pop_back();
    }
}

int main()
{
    for(int i = 0; i < 8; i++)
    {
        string s; cin >> s;
        Grid.push_back(s);
    }
    for(int i = 0; i < 8; i++)
    {
        if(Grid[0][i] == '*') continue;
        V.push_back({0, i});
        rec(1);
        V.pop_back();
    }
    cout << c;
}