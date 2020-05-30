#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

const int N = 105;

map < string, vector < string > > neighbores;
map < string, bool > mark;

void dfs(string v) {
    mark[v] = true;
    vector < string > vNeighbors = neighbores[v];
    for (int i = 0; i < vNeighbors.size(); i++) {
        if (!mark[vNeighbors[i]]) {
            dfs(vNeighbors[i]);
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
        getline(cin, name);

        vector < string > empty;
        neighbores[key] = empty;
        mark[key] = false;
    }
    for (int i = 0; i < m; i++) {
        string v, u;
        cin >> v >> u;
        neighbores[v].push_back(u);
        neighbores[u].push_back(v);
    }
    int ans = 0;
    for (map < string, vector < string > >::iterator it = neighbores.begin(); it != neighbores.end(); it++) {
        string v = it -> first;
        if (!mark[v]) {
            ans++;
            dfs(v);
        }
    }
    cout << ans;
}