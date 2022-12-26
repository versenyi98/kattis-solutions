#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    while (cin >> n >> m) {

        string map[n];
        int color[n][m];
        for (int i = 0; i < n; i++) {
            cin >> map[i];
            for (int j = 0; j < m; j++) {
                color[i][j] = -1;
            }
        }

        int current_color = 0;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (color[i][j] == -1) {
                    current_color++;

                    queue<int> qx, qy;

                    qx.push(i);
                    qy.push(j);

                    while (qx.size()) {
                        int x = qx.front();
                        int y = qy.front();

                        qx.pop();
                        qy.pop();

                        color[x][y] = current_color;

                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if (nx < 0 || ny < 0 || nx == n || ny == m || color[nx][ny] != -1 || map[nx][ny] != map[i][j]) {
                                continue;
                            }

                            color[nx][ny] = current_color;

                            qx.push(nx);
                            qy.push(ny);

                        }
                    }
                }
            }
        }

        int queries;
        cin >> queries;

        while (queries--) {
            int sx, sy, fx, fy;
            cin >> sx >> sy >> fx >> fy;

            if (color[sx - 1][sy - 1] != color[fx - 1][fy - 1]) {
                cout << "neither" << endl;
            } else if (map[sx - 1][sy - 1] == '0') {
                cout << "binary" << endl;
            } else {
                cout << "decimal" << endl;
            }
        }

    }

    return 0;
}