#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int64_t n, timeout;

    while (cin >> n >> timeout) {
        vector<pair<int64_t, int64_t>> v(n);
        for (int64_t i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }

        sort(v.begin(), v.end(), [] (pair<int64_t, int64_t> a, pair<int64_t, int64_t> b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });

        multiset<int64_t> ms;

        int64_t res = 0;

        for (int i = 0; i < n; i++) {
            auto it = ms.lower_bound(v[i].first - timeout);
            if (it == ms.end()) {
                ms.insert(v[i].first + v[i].second);
            } else if (*it <= v[i].first) {
                res++;
                ms.erase(it);
                ms.insert(v[i].first + v[i].second);
            } else {
                ms.insert(v[i].first + v[i].second);
            }
        }
        cout << res << endl;
    }

    return 0;
}