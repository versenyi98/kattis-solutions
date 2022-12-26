#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    while (cin >> n >> m) {
        string map[n];

        for (int i = 0; i < n; i++) {
            cin >> map[i];
        }

        queue<int> start_x;
        queue<int> start_y;

        for (int i = 0; i < n; i++) {
            start_x.push(i);
            start_x.push(i);
            start_y.push(0);
            start_y.push(m - 1);
        }

        for (int j = 0; j < m; j++) {
            start_x.push(0);
            start_x.push(n - 1);
            start_y.push(j);
            start_y.push(j);
        }

        while (start_x.size()) {
            int x = start_x.front();
            int y = start_y.front();

            start_x.pop();
            start_y.pop();

            if (map[x][y] == '1') continue;

            map[x][y] = 'S';

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx == n || ny == m) continue;
                if (map[nx][ny] != '0') continue;

                map[nx][ny] = 'S';
                start_x.push(nx);
                start_y.push(ny);
            }
        }

        int area = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == '1') {
                    queue<int> qx, qy;
                    qx.push(i);
                    qy.push(j);

                    while (qx.size()) {
                        int x = qx.front();
                        int y = qy.front();

                        qx.pop();
                        qy.pop();

                        map[i][j] = 'L';

                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if (nx < 0 || ny < 0 || nx == n || ny == m) {
                                area++;
                                continue;
                            }

                            if (map[nx][ny] == 'S') {
                                area++;
                                continue;
                            }

                            if (map[nx][ny] == '1') {
                                map[nx][ny] = 'L';
                                qx.push(nx);
                                qy.push(ny);
                            }
                        }
                    }
                }
            }
        }
        cout << area << endl;
    }
}