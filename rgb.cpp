
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, d, r0, g0, b0;

    cin>>n>>m>>d>>r0>>g0>>b0;

    vector<vector<int>> R(n, vector<int>(m));
    vector<vector<int>> G(n, vector<int>(m));
    vector<vector<int>> B(n, vector<int>(m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> R[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> G[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> B[i][j];
        }
    }

    vector<pair<int, int>> targets;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int color_dist = abs(R[i][j] - r0) + abs(G[i][j] - g0) + abs(B[i][j] - b0);
            if (color_dist <= d){
                targets.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            bool found = false;
            for (auto p : targets){
                if (abs(i - p.first) + abs(j - p.second) <= d){
                    found = true;
                    break;
                }
            }
            if (found){
                cout << 1 << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}