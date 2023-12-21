#include <bits/stdc++.h>
//#define endl "\n"

using namespace std;

int ans;

int bfs(int idx, const vector<int> val, const vector<int>  v[10000]) {

    int tmp;
    int res = val[idx];
    for (auto i : v[idx]) {
        tmp = bfs(i, val, v);
        ans += abs(tmp);
        res += tmp;
    }

    return res - 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while (cin >> n, n) {
        ans = 0;

        vector<int> v[n];
        vector<int> val;
        bool root[n] = {false};
        val.resize(n);

        for (int i = 0; i < n; i++) {

            int id_ = 0;
            cin >> id_;
            id_--;

            int val_;
            cin >> val_;
            val[id_] = val_;

            int m;
            cin >> m;
            for (int j = 0; j < m; j++) {
                int id;
                cin >> id;
                root[id - 1] = true;
                v[id_].push_back(id - 1);
            }
        }
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (!root[i]) r = i;
        }
        bfs(r, val, v);
        cout << ans << endl;
    }

    return 0;
}