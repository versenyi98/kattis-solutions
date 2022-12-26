#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    for (int tt = 0; tt < test_cases; tt++) {
        cout << "Case #" << tt + 1 << ": ";

        int n;
        cin >> n;

        vector<int64_t> v[2];
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < n; i++) {
                int64_t a; cin >> a;
                v[j].push_back(a);
            }
            sort(v[j].begin(), v[j].end());
        }

        int64_t minimal = 0;
        for (int i = 0; i < n; i++) {
            minimal += v[0][i] * v[1][n - 1 - i];
        }
        cout << minimal << endl;
    }

    return 0;
}