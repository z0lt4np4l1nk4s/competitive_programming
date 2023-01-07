//https://cses.fi/problemset/task/1625

#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

vector<char> moves;
bool visited[49];
string path;
int c = 0;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dir[4] = {'U', 'R', 'D', 'L'};

bool isInvalid(int x)
{
    return x < 0 || x > 6;
}

void rec(int x, int y)
{
    if(moves.size() == 48)
    {
        if(x == 6 && y == 0) c++;
        return;
    }
    if(x == 6 && y == 0) return;
    bool valid[4];
    memset(valid, true, sizeof(valid));
    for(int i = 0; i < 4; i++)
    {
        if(path[moves.size()] == '?' || path[moves.size()] == dir[i])
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            int ind = newX * 7 + newY;
            if(isInvalid(newX) || isInvalid(newY) || visited[ind]) continue;
            valid[i] = visited[ind];
        }
    }
    if(!valid[2] && !valid[0] && valid[1] && valid[3]) return;
    if(valid[2] && valid[0] && !valid[1] && !valid[3]) return;
    if(!isInvalid(x-1) && !isInvalid(y+1) && visited[(x-1) * 7 + y+1] && !valid[1] && !valid[0]) return;
    if(!isInvalid(x-1) && !isInvalid(y-1) && visited[(x-1) * 7 + y-1] && !valid[3] && !valid[0]) return;
    if(!isInvalid(x+1) && !isInvalid(y-1) && visited[(x+1) * 7 + y-1] && !valid[3] && !valid[2]) return;
    if(!isInvalid(x+1) && !isInvalid(y+1) && visited[(x+1) * 7 + y+1] && !valid[1] && !valid[2]) return;
    for(int i = 0; i < 4; i++)
    {
        if(valid[i]) continue;
        int newX = x + dx[i];
        int newY = y + dy[i];
        moves.push_back(dir[i]);
        visited[newX * 7 + newY] = true;
        rec(newX, newY);
        visited[newX * 7 + newY] = false;
        moves.pop_back();
    }
}

int main()
{
    memset(visited, false, sizeof(visited));
    visited[0] = true;
    cin >> path;
    rec(0, 0);
    cout << c;
}