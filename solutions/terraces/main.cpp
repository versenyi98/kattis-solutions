#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n, m;

    while (cin >> n >> m) {
        vector<vector<pair<int, int>>> connected_components;

        int grid[m][n];
        bool visited[m][n];

        pair<int, int> directions[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
                visited[i][j] = false;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == false) {
                    visited[i][j] = true;

                    vector<pair<int, int>> component;

                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while (q.size() > 0) {
                        auto front = q.front();
                        q.pop();

                        component.push_back(front);

                        for (int k = 0; k < 4; k++) {
                            int ii = front.first + directions[k].first;
                            int jj = front.second + directions[k].second;

                            if (ii >= 0 && ii < m && jj >= 0 && jj < n && !visited[ii][jj] && grid[ii][jj] == grid[front.first][front.second]) {
                                visited[ii][jj] = true;
                                q.push({ii, jj});
                            }
                        }
                    }

                    connected_components.push_back(component);
                }
            }
        }

        int answer = 0;

        for (auto cc : connected_components) {
            bool good = true;

            for (auto c : cc) {
                for (int i = 0; i < 4; i++) {
                    int ii = c.first + directions[i].first;
                    int jj = c.second + directions[i].second;

                    if (ii >= 0 && ii < m && jj >= 0 && jj < n && grid[c.first][c.second] > grid[ii][jj]) {
                        good = false;
                        break;
                    }
                }
                if (!good) {
                    break;
                }
            }

            if (good) {
                answer += cc.size();
            }
        }

        cout << answer << endl;
    }

    return 0;
}