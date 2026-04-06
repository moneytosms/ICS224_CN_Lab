#include <bits/stdc++.h>
using namespace std;

const int inf = 10000000;
const int num_routers = 4;

void print_tables(int cost_matrix[][num_routers],
                  vector<vector<int>> &next_hop) {
  for (int i = 0; i < num_routers; i++) {
    cout << "Routing table for: " << char('A' + i) << endl;
    cout << "Dest\tCost\tNext_hop" << endl;
    for (int j = 0; j < num_routers; j++) {
      cout << char('A' + j) << "\t" << cost_matrix[i][j] << "\t"
           << char('A' + next_hop[i][j]) << endl;
    }
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cost_matrix[num_routers][num_routers] = {
      {0, 2, inf, 1}, {2, 0, 3, 7}, {inf, 3, 0, 11}, {1, 7, 11, 0}};

  vector<vector<int>> next_hop(num_routers, vector<int>(num_routers, -1));

  for (int i = 0; i < num_routers; i++) {
    for (int j = 0; j < num_routers; j++) {
      if (cost_matrix[i][j] != inf) {
        next_hop[i][j] = j;
      }
    }
  }

  for (int i = 0; i < num_routers; i++) {
    cout << "Iteration" << i + 1 << ": " << endl;
    for (int j = 0; j < num_routers; j++) {
      if (cost_matrix[i][j] != inf) {
        for (int k = 0; k < num_routers; k++) {
          if (cost_matrix[j][k] != inf &&
              cost_matrix[i][k] > cost_matrix[i][j] + cost_matrix[j][k]) {
            cost_matrix[i][k] = cost_matrix[i][j] + cost_matrix[j][k];
            next_hop[i][k] = next_hop[i][j];
          }
        }
      }
    }
    print_tables(cost_matrix, next_hop);
  }

  return 0;
}
