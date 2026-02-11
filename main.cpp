#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    long long w;
};

class Graph {
public:
    explicit Graph(int n) : n_(n), adj_(n) {}

    void addEdge(int u, int v, long long w, bool undirected = true) {
        adj_[u].push_back({v, w});
        if (undirected) adj_[v].push_back({u, w});
    }

    // BFS connectivity (treat weights as irrelevant)
    bool connected(int s, int t) const {
        vector<char> vis(n_, false);
        queue<int> q;
        vis[s] = true;
        q.push(s);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) return true;
            for (auto &e : adj_[u]) {
                if (!vis[e.to]) {
                    vis[e.to] = true;
                    q.push(e.to);
                }
            }
        }
        return false;
    }

    // Dijkstra shortest path + reconstruct path
    pair<long long, vector<int>> dijkstraPath(int s, int t) const {
        const long long INF = numeric_limits<long long>::max() / 4;
        vector<long long> dist(n_, INF);
        vector<int> parent(n_, -1);

        // (dist, node)
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        dist[s] = 0;
        pq.push({0, s});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;          // stale entry
            if (u == t) break;                   // early exit

            for (auto &e : adj_[u]) {
                if (dist[u] + e.w < dist[e.to]) {
                    dist[e.to] = dist[u] + e.w;
                    parent[e.to] = u;
                    pq.push({dist[e.to], e.to});
                }
            }
        }

        if (dist[t] == INF) return {INF, {}};

        vector<int> path;
        for (int cur = t; cur != -1; cur = parent[cur]) path.push_back(cur);
        reverse(path.begin(), path.end());
        return {dist[t], path};
    }

private:
    int n_;
    vector<vector<Edge>> adj_;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input format:
    // n m
    // u v w   (m lines, 0-indexed nodes)
    // s t
    //
    // Example:
    // 6 7
    // 0 1 4
    // 0 2 2
    // 2 1 1
    // 1 3 5
    // 2 3 8
    // 3 4 3
    // 4 5 2
    // 0 5

    int n, m;
    cin >> n >> m;
    Graph g(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w, true);
    }

    int s, t;
    cin >> s >> t;

    cout << "Connected (BFS): " << (g.connected(s, t) ? "YES" : "NO") << "\n";

    auto [dist, path] = g.dijkstraPath(s, t);
    if (path.empty()) {
        cout << "Shortest path (Dijkstra): NONE\n";
    } else {
        cout << "Shortest distance (Dijkstra): " << dist << "\n";
        cout << "Path: ";
        for (int i = 0; i < (int)path.size(); i++) {
            cout << path[i] << (i + 1 == (int)path.size() ? "\n" : " -> ");
        }
    }

    return 0;
}