#include <bits/stdc++.h>
using namespace std;
int a[15][15][15];
bool inRange(int x, int y, int z, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && z >= 0 && z < n);
}
int main() {
    int n;
    cin >> n;
    for (int z = 0; z < n; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                cin >> a[z][y][x];
            }
        }
    }
    int dir[13][3] = {
        {1, 0, 0}, {0, 1, 0}, {0, 0, 1},// 平行軸 (3個)
        {1, 1, 0}, {1, -1, 0}, {1, 0, 1}, {1, 0, -1}, {0, 1, 1}, {0, 1, -1}, // 平面對角線 (6個)
        {1, 1, 1}, {1, 1, -1}, {1, -1, 1}, {1, -1, -1} // 立體對角線 (4個)
    };
    int ans = 0;
    for (int z = 0; z < n; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (a[z][y][x] == 1) {
                    for (int d_idx = 0; d_idx < 13; d_idx++) {
                        int targetZ = z + (n - 1) * dir[d_idx][0];
                        int targetY = y + (n - 1) * dir[d_idx][1];
                        int targetX = x + (n - 1) * dir[d_idx][2];
                        if (inRange(targetZ, targetY, targetX, n)) {
                            bool isLine = true;
                            for (int s = 0; s < n; s++) {
                                int curZ = z + s * dir[d_idx][0];
                                int curY = y + s * dir[d_idx][1];
                                int curX = x + s * dir[d_idx][2];
                                if (a[curZ][curY][curX] == 0) {
                                    isLine = false;
                                    break;
                                }
                            }
                            if (isLine) ans++;
                        }
                    }
                }

            }
        }
    }
    cout << ans << endl;
    return 0;
}