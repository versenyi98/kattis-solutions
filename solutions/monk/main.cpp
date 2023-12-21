#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    while (cin >> n >> m) {
        vector<pair<double, double>> ascend, descend;

        int h, t;
        double high = 0.0;
        double low = 0.00000001;

        double total_h = 0.0;

        for (int i = 0; i < n; i++) {
            cin >> h >> t;
            ascend.push_back({h, t});
            high += t;
            total_h += h;
        }

        for (int i = 0; i < m; i++) {
            cin >> h >> t;
            descend.push_back({h, t});
        }

        while (abs(low - high) > 0.00000001) {
            double mid = (low + high) / 2.0;

            double mid_cop = mid;

            double up_h = 0.0;
            double down_h = total_h;

            for (int i = 0; i < n; i++) {
                up_h += min(1.0, mid / ascend[i].second) * ascend[i].first;
                mid -= ascend[i].second;
                if (mid <= 0) break;
            }

            for (int i = 0; i < m; i++) {
                down_h -= min(1.0, mid_cop / descend[i].second) * descend[i].first;
                mid_cop -= descend[i].second;
                if (mid_cop <= 0) break;
            }

            if (up_h < down_h) {
                low = (low + high) / 2.0;
            } else {
                high = (low + high) / 2.0;
            }
        }

        printf("%.7f\n", high);
    }

    return 0;
}