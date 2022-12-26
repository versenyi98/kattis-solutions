#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int64_t n, m;

    while (cin >> n >> m) {
        vector<pair<int64_t, int64_t>> v(n), pos, neg;
        int64_t res = 0;
        for (int64_t i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

        sort(v.begin(), v.end());

        for (int64_t i = 0; i < v.size(); i++) {
            if (v[i].second >= m) {
                res += abs(v[i].first) * 2 * (v[i].second / m);
                v[i].second = v[i].second % m;
            }

            if (v[i].first < 0) {
                neg.push_back(v[i]);
            } else {
                pos.push_back(v[i]);
            }
        }

        int64_t dist = 0;
        int64_t load = 0;
        int64_t idx = 0;

        while (idx != neg.size()) {
            if (neg[idx].second + load > m) {
                neg[idx].second = neg[idx].second - (m - load);
                res += dist * 2;
                dist = 0;
                load = 0;
            } else {
                dist = max(dist, -neg[idx].first);
                load += neg[idx].second;
                idx++;
            }
        }
        if (load) res += 2 * dist;

        dist = load = 0;
        idx = pos.size() - 1;
        while (idx != -1) {
            if (pos[idx].second + load > m) {
                pos[idx].second = pos[idx].second - (m - load);
                res += dist * 2;
                dist = 0;
                load = 0;
            } else {
                dist = max(dist, pos[idx].first);
                load += pos[idx].second;
                idx--;
            }
        }
        if (load) res += 2 * dist;

        cout << res << endl;
    }

    return 0;
}