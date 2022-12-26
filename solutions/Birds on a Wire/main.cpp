#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int64_t l, n, m;

    while (cin >> l >> n >> m) {
        vector<int64_t> v(m);
        for (int i = 0; i < m; i++) cin >> v[i];

        sort(v.begin(), v.end());
        int64_t res = 0;

        for (int i = 0; i < static_cast<int>(v.size()) - 1; i++) {
            res += max((v[i + 1] - v[i]) / n - 1, 0l);
        }

        if (v.size()) {
            res += (v[0] - 6) / n;
            res += (l - 6 - v.back()) / n;
        } else if (l > 11) {
            res += (l - 6 - 6) / n + 1;
        }

        cout << res << endl;

    }

    return 0;
}