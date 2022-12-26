#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    while (cin >> n >> m) {
        int ans = 0;
        vector<pair<int, int>> v(n);

        bool available[m + 1];
        for (int i = 0; i < m + 1; i++) available[i] = true;

        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }

        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            return (a.first == b.first && a.second > b.second) || a.first > b.first;
        });

        for (auto i : v) {
            while (i.second >= 0 && !available[i.second]) {
                i.second--;
            }

            if (i.second >= 0) {
                available[i.second] = false;
                ans += i.first;
            }
        }
        cout << ans << endl;

    }

    return 0;
}