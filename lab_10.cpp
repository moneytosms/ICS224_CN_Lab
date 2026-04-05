#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void print_tables(int step, vector<vector<int>> &dist,
                  vector<vector<int>> &next_hop) {
  cout << "\nStep " << step << ":\n";

  for (int i = 0; i < dist.size(); i++) {
    cout << "Router " << i << ":\n";
    cout << "Dest\tDist\tNext Hop\n";

    for (int j = 0; j < dist.size(); j++) {
      cout << j << "\t";

      if (dist[i][j] == INF)
        cout << "INF\t";
      else
        cout << dist[i][j] << "\t";

      if (next_hop[i][j] == -1)
        cout << "-";
      else
        cout << next_hop[i][j];

      cout << "\n";
    }
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cout << "Enter number of routers and connections: ";
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n);

  cout << "Enter edges (u v w):\n";
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  vector<vector<int>> dist(n, vector<int>(n, INF));
  vector<vector<int>> next_hop(n, vector<int>(n, -1));

  // Initialization
  for (int i = 0; i < n; i++) {
    dist[i][i] = 0;
    next_hop[i][i] = i;

    for (int k = 0; k < adj[i].size(); k++) {
      int neighbor = adj[i][k].first;
      int weight = adj[i][k].second;

      dist[i][neighbor] = weight;
      next_hop[i][neighbor] = neighbor;
    }
  }

  int step = 0;
  print_tables(step++, dist, next_hop);

  // Run exactly (n - 1) iterations
  for (int iter = 1; iter <= n - 1; iter++) {

    vector<vector<int>> new_dist = dist;
    vector<vector<int>> new_next = next_hop;

    for (int i = 0; i < n; i++) {
      for (int k = 0; k < adj[i].size(); k++) {
        int neighbor = adj[i][k].first;
        int weight = adj[i][k].second;

        for (int j = 0; j < n; j++) {

          if (dist[neighbor][j] == INF)
            continue;

          int new_cost = dist[i][neighbor] + dist[neighbor][j];

          if (new_cost < dist[i][j]) {
            new_dist[i][j] = new_cost;
            new_next[i][j] = neighbor;
          }
        }
      }
    }

    dist = new_dist;
    next_hop = new_next;

    print_tables(step++, dist, next_hop);
  }

  cout << "Completed " << (n - 1) << " iterations.\n";
  return 0;
}
