#include <bits/stdc++.h>

using namespace std;

int main() {

    int m, n;

    while (cin >> m >> n) {
        string maze[n];
        bool should_be_careful[n][m];
        bool visited[n][m];
        queue<pair<int, int>> q;
        pair<int, int> player;

        for (int i = 0; i < n; i++) {
            cin >> maze[i];
            if (maze[i].find('P') != string::npos) {
                player = {i, maze[i].find('P')};
            }
            for (int j = 0; j < m; j++) {
                should_be_careful[i][j] = false;
                visited[i][j] = false;
                if (maze[i][j] == 'T')  {
                    q.push({i, j});
                    q.push({i + 1, j});
                    q.push({i, j + 1});
                    q.push({i - 1, j});
                    q.push({i, j - 1});
                }
            }
        }

        while (q.size()) {
            auto front = q.front();
            q.pop();

            int f = front.first;
            int s = front.second;

            if (f < 0 || s < 0 || f == n || s == m) continue;

            should_be_careful[f][s] = true;
        }

        q.push(player);
        int counter = 0;

        while (q.size()) {
            auto front = q.front();
            q.pop();

            int f = front.first;
            int s = front.second;

            if (f < 0 || s < 0 || f == n || s == m || visited[f][s]) continue;
            visited[f][s] = true;
            if (maze[f][s] == 'G') counter++;
            if (should_be_careful[f][s] || maze[f][s] == '#') continue;

            q.push({f + 1, s});
            q.push({f, s + 1});
            q.push({f - 1, s});
            q.push({f, s - 1});
        }
        
        cout << counter << endl;
    }
}