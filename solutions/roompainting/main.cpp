#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    while (cin >> n >> m) {
        vector<uint64_t> v;
        for (int i = 0; i < n; i++) {
            uint64_t a;
            cin >> a;
            v.push_back(a);
        }

        sort(v.begin(), v.end());

        uint64_t loss = 0;

        for (int i = 0; i < m; i++) {
            uint64_t a; cin >> a;
            loss += *lower_bound(v.begin(), v.end(), a) - a;
        }

        cout << loss << endl;
    }

    return 0;
}