#include <bits/stdc++.h>
#define endl "\n"
#define f first
#define s second
using namespace std;

int main() {

    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    int test_case = 0;

    while (test_case++, cin >> n >> m) {
        vector<pair<int, int>> r;
        r.push_back({n, m});
        for (int i = 0; i < 2; i++) {
            cin >> n >> m;
            r.push_back({n, m});
        }

        vector<int> p;
        for (int i = 0; i < 3; i++) {
            p.push_back(i);
        }

        bool good = false;

        do {
            for (int i = 0; i < 2 * 2 * 2; i++) {
                // swap if horizontal
                for (int j = 0; j < 3; j++) {
                    if ((i & (int)pow(2, j)) != 0) {
                        swap(r[j].f, r[j].s);
                    }
                }

                // #1 next to each other (or under each other)
                if (r[p[0]].f + r[p[1]].f + r[p[2]].f == r[p[0]].s && (r[p[0]].s == r[p[1]].s && r[p[2]].s == r[p[0]].s)) {
                    good = true;
                }

                // #2 2 next to each other, 1 under (or rotated version)
                if (r[p[0]].f + r[p[1]].f == r[p[2]].f && r[p[2]].f == r[p[0]].s + r[p[2]].s && r[p[1]].s == r[p[0]].s) {
                    good = true;
                }

                // swap back
                for (int j = 0; j < 3; j++) {
                    if ((i & (int)pow(2, j)) != 0) {
                        swap(r[j].f, r[j].s);
                    }
                }

            }
        } while (next_permutation(p.begin(), p.end()));
        if (good) {
            cout << "YES\n";
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}