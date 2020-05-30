#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

const int N = 2005;

map < string, vector < string > > neighbores;
map < string, string > keyToName;
map < string, int > ans;
string inputOrder[N];

void bfs(string src) {
    queue < string > q;
    q.push(src);
    while (!q.empty()) {
        string v = q.front();
        q.pop();
        for (vector < string >::iterator it = neighbores[v].begin(); it != neighbores[v].end(); it++) {
            if (ans[*it] == -1) {
                ans[*it] = ans[v] + 1;
                q.push(*it);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string key;
        string name;
        cin >> key;
        char _ = getchar(); //ignore space character
        getline(cin, name);
        inputOrder[i] = key;
        keyToName[key] = name;
        ans[key] = -1;
        vector < string > empty;
        neighbores[key] = empty;
    }
    for (int i = 0; i < m; i++) {
        string v, u;
        cin >> v >> u;
        neighbores[v].push_back(u);
        neighbores[u].push_back(v);
    }
    string srcKey;
    cin >> srcKey;
    ans[srcKey] = 0;
    bfs(srcKey);
    for (int i = 0; i < n; i++) {
        cout << keyToName[inputOrder[i]] << ' ' << ans[inputOrder[i]] << endl;
    }
}