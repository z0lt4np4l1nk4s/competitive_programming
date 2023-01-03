//https://codeforces.com/contest/1760/problem/D

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() { 
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> V;
    for(int i = 0; i < n; i++)
    {
      int a; cin >> a;
      V.push_back(a);
    }
    V.erase(unique(V.begin(), V.end()), V.end());
    int c = 0;
    for (int i = 0; i < V.size(); i++) if ((i == 0 || V[i - 1] > V[i]) && (i == V.size() - 1 || V[i] < V[i + 1])) c++;
    cout << (c == 1 ? "YES" : "NO") << endl;
  }
}