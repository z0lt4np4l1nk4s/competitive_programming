//https://cses.fi/problemset/task/1755

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

char c;

bool isEqual(const std::pair<char, int>& element)
{
    return element.first ==  c;
}

bool cmp(pair<char, int> left, pair<char,int> right)
{
    if(left.second & 1 && right.second & 1) // both are odd
    {
        return left.second < right.second;
    }
    else if(left.second & 1) // left is odd
    {
        return false;
    }
    else if(right.second & 1) // right is odd
    {
        return true;
    }

    // both are even
    return left.second < right.second;
}

int main()
{
    string s; cin >> s;
    vector<pair<char, int>> V;
    for(int i = 0; i < s.size(); i++)
    {
        c = s[i];
        auto it = find_if(V.begin(), V.end(), isEqual);
        if(it != V.end())
        {
            (*it).second++;
        }
        else V.push_back({s[i], 1});
    }
    sort(V.begin(), V.end(), cmp);
    string res = "";
    for(int i = 0; i < V.size(); i++)
    {
        for(int j = 0; j < V[i].second / 2; j++) res += V[i].first;
    }
    for(int i = V.size() - 1; i >= 0; i--)
    {
        for(int j = 0; j < (V[i].second / 2) + (V[i].second % 2); j++) res += V[i].first;
    }
    string p = res;
    reverse(p.begin(), p.end());
    if(p == res) cout << res;
    else cout << "NO SOLUTION";
}