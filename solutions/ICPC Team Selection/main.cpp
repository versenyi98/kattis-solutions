#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < 3 * n; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }

        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += v[n + i * 2];
        }

        cout << ans << endl;
    }

    return 0;
}