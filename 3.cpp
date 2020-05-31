#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <climits>
#include <cstdio>
#include <utility>

using namespace std;

map < string, vector < string > > neighbores;
map < string, vector < double > > w; //Store weights between vertices
map < string, double > ans;
map < string, vector < string > > path;

void go(string src) { //Dijkstra
    priority_queue < pair < double, string > > pq;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        string v = pq.top().second;
        pq.pop();
        vector < double >::iterator it2 = w[v].begin();
        for (vector < string >::iterator it = neighbores[v].begin(); it != neighbores[v].end(); it++, it2++) {
            if (ans[v] + *it2 < ans[*it]) {
                ans[*it] = ans[v] + *it2;
                path[*it] = path[v];
                path[*it].push_back(*it);
                pq.push(make_pair(-ans[*it], *it));
            }
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string key;
        string name;
        cin >> key;
        getline(cin, name); //Ignore given name
        ans[key] = INT_MAX; //Infinity
        vector < string > empty;
        vector < double > empty2;
        neighbores[key] = empty;
        w[key] = empty2;
    }
    for (int i = 0; i < m; i++) {
        string v, u;
        double w0;
        cin >> v >> u >> w0;
        neighbores[v].push_back(u);
        neighbores[u].push_back(v);
        w[v].push_back(w0);
        w[u].push_back(w0);
    }
    string srcKey, destKey;
    cin >> srcKey >> destKey;
    ans[srcKey] = 0;
    path[srcKey].push_back(srcKey);
    go(srcKey);
    printf("%.2lf\n", ans[destKey]);
    for (int i = 0; i < path[destKey].size(); i++) {
        cout << path[destKey][i] << ' ';
    }
}