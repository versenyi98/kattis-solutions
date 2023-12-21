#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int cases = 0;
    while (cin >> n && n) {
        cout << "Case " << ++cases << ":" << endl;
        int nums[n];
        vector<int> sums;

        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            for (int j = 0; j < i; j++) {
                sums.push_back(nums[i] + nums[j]);
            }
        }

        sort(sums.begin(), sums.end());

        cin >> m;
        int q;
        for (int i = 0; i < m; i++) {
            cin >> q;
            auto l1 = lower_bound(sums.begin(), sums.end(), q);
            if (l1 == sums.end()) l1--;
            auto l2 = l1;
            if (l2 != sums.begin()) l2--;
            int res;
            if (*l1 - q < q - *l2) {
                res = *l1;
            } else {
                res = *l2;
            }
            cout << "Closest sum to " << q << " is " << res << "." << endl;
        }
    }

    return 0;
}