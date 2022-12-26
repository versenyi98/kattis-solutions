#include <bits/stdc++.h>

using namespace std;

int main() {

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int n, m;

    while (cin >> n >> m) {
        string map[n];

        for (int i = 0; i < n; i++) {
            cin >> map[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 'C') {
                    bool has_island = false;

                    queue<int> qx, qy;
                    queue<int> px, py;

                    qx.push(i);
                    qy.push(j);
                    px.push(i);
                    py.push(j);

                    while (qx.size()) {
                        int x = qx.front();
                        int y = qy.front();

                        qx.pop();
                        qy.pop();

                        map[x][y] = 'P';

                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if (nx < 0 || ny < 0 || nx == n || ny == m) {
                                continue;
                            }

                            if (map[nx][ny] == 'C') {
                                qx.push(nx);
                                qy.push(ny);
                                px.push(nx);
                                py.push(ny);
                                map[nx][ny] = 'P';
                            } else if (map[nx][ny] == 'L') {
                                has_island = true;
                            }
                        }
                    }

                    char color = has_island ? 'L' : 'W';
                    while(px.size()) {
                        int x = px.front();
                        int y = py.front();

                        map[x][y] = color;

                        px.pop();
                        py.pop();
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 'L') {
                    ans++;

                    queue<int> qx, qy;

                    qx.push(i);
                    qy.push(j);

                    while (qx.size()) {
                        int x = qx.front();
                        int y = qy.front();

                        qx.pop();
                        qy.pop();

                        map[x][y] = 'W';

                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if (nx < 0 || ny < 0 || nx == n || ny == m) {
                                continue;
                            }

                            if (map[nx][ny] == 'L') {
                                qx.push(nx);
                                qy.push(ny);
                                map[nx][ny] = 'W';
                            }
                        }
                    }
                }
            }
        }

        cout << ans << endl;
    }
}