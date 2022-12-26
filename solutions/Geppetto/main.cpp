#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    while (cin >> n >> m) {

        set<pair<int, int>> s;

        int x, y;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            s.insert({max(x, y) - 1, min(x, y) - 1});
        }

        int p = 1;
        for (int i = 0; i < n; i++) p *= 2;

        int res = 0;

        for (int i = 0; i < p; i++) {
            bool good = true;

            for (auto ss : s) {
                if (i & (int)pow(2, ss.first) && i & (int)pow(2, ss.second)) {
                    good = false;
                    break;
                }
            }

            if (good) {
                res++;
            }
        }
        cout << res << endl;
    }

    return 0;
}