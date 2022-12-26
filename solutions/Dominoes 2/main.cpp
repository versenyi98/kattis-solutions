#include <bits/stdc++.h>

using namespace std;

int main() {

    int test_cases;
    cin >> test_cases;

    for (int oi = 0; oi < test_cases; oi++) {
        int n, m, l;
        cin >> n >> m >> l;

        bool knocked_over[n];
        vector<int> knocks_over[n];
        queue<int> q;
        int counter = 0;

        for (int i = 0; i < n; i++) knocked_over[i] = false;

        int x, y;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;

            knocks_over[x - 1].push_back(y - 1);
        }

        for (int i = 0; i < l; i++) {
            cin >> x;
            q.push(x - 1);
        }

        while (q.size()) {
            auto front = q.front();
            q.pop();
            
            if (knocked_over[front]) continue;
            knocked_over[front] = true;

            counter++;

            for (auto i : knocks_over[front]) {
                if (!knocked_over[i]) {
                    q.push(i);
                }
            }    
        }

        cout << counter << endl;
    }
}