#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    while (cin >> n) {
        set<int> s;
        vector<int> weights;
        vector<int> a(n), b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            s.insert(b[i]);
        }

        weights.push_back(0);
        for (auto i : s) {
            weights.push_back(i);
        }

        int high = weights.size() - 1;
        int low = 0;
        int res = 0;

        while (high >= low) {
            int mid = (high + low) / 2;

            int last = -1;
            int last2 = -1;
            bool wrong = false;
            for (int i = 0; i < n; i++) {
                if (a[i] > weights[mid]) {
                    if (last == -1) {
                        last = a[i];
                    } else if (last == a[i]) {
                        last = -1;
                    } else {
                        wrong = true;
                    }
                }

                if (b[i] > weights[mid]) {
                    if (last2 == -1) {
                        last2 = b[i];
                    } else if  (last2 == b[i]) {
                        last2 = -1;
                    } else {
                        wrong = true;
                    }
                }

            }
            if (last != -1) wrong = true;
            if (last2 != -1) wrong = true;

            if (wrong) {
                low = mid + 1;
            } else {
                res = mid;
                high = mid - 1;
            }
        }

        cout << weights[res] << endl;
    }

    return 0;
}