#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while (cin >> n, n) {
        double profit[2000];
        for (int i = 0; i < 2000; i++) {
            profit[i] = -0.08;
        }
        for (int i = 0; i < n; i++) {
            int stamp;
            double price;
            cin >> stamp >> price;
            profit[stamp] += price;
        }

        double sum = 0;
        int current_start = 0, current_len = -1;
        double ans = 0;
        int start = 5000, len = 5000;

        for (int i = 0; i < 2000; i++) {
            current_len++;
            sum += profit[i];

            if (sum > ans ||
                (sum == ans && current_len < len) ||
                (sum == ans && current_len == len && current_start < start)) {

                ans = sum;
                len = current_len;
                start = current_start;
            }

            if (sum < 10e-9) {
                sum = 0;
                current_start = i + 1;
                current_len = -1;
            }
        }

        if (ans <= 0) {
            printf("no profit\n");
        } else {
            printf("%.2f %d %d\n", ans, start, start + len);
        }
    }

    return 0;
}