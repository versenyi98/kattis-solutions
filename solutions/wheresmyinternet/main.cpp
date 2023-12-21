#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    while (cin >> n >> m) {
        vector<bool> visited(n);
        vector<int> edges[n];

        int from, to;
        for (int i = 0; i < m; i++) {
            cin >> from >> to;
            from--; to--;
            edges[from].push_back(to);
            edges[to].push_back(from);
        }

        queue<int> q;
        q.push(0);

        while (q.size()) {
            int front = q.front();
            q.pop();

            visited[front] = true;
            for (int a : edges[front]) {
                if (!visited[a]) q.push(a);
            }
        }

        bool good = true;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cout << i + 1 << endl;
                good = false;
            }
        }

        if (good) {
            cout << "Connected" << endl;
        }
    }

    return 0;
}