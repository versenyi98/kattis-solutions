#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tt;
    cin >> tt;

    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<bool> visited(n);
        vector<int> edges[n];

        int from, to;
        for (int i = 0; i < m; i++) {
            cin >> from >> to;
            edges[from].push_back(to);
            edges[to].push_back(from);
        }

        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                counter++;
                queue<int> q;
                q.push(i);

                while (q.size()) {
                    int front = q.front(); q.pop();
                    visited[front] = true;
                    for (int a : edges[front]) {
                        if (!visited[a]) q.push(a);
                    }
                }
            }
        }

        cout << max(0, counter - 1) << endl;
    }

    return 0;
}