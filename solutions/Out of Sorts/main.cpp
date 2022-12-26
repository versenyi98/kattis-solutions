#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long n, m, a, c, x0;

    while (cin >> n >> m >> a >> c >> x0) {
        vector<long> v;

        for (long i = 0; i < n; i++) {
            x0 = (a * x0 + c) % m;
            v.push_back(x0);
        }

        int counter = 0;

        for (auto target : v) {
            long high = n - 1;
            long low = 0;

            while (high >= low) {

                long mid = (high + low) / 2;

                if (v[mid] == target) {
                    counter++;
                    break;
                }

                if (v[mid] > target) {
                    high = mid - 1;
                }

                if (v[mid] < target) {
                    low = mid + 1;
                }
            }
        }

        cout << counter << endl;
    }

    return 0;
}