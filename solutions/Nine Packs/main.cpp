#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    int ans = 8000;

    vector<int> hotdogs_dp(100001, 4000), buns_dp(100001, 4000);
    hotdogs_dp[0] = 0;
    buns_dp[0] = 0;
    
    cin >> n;
    int sum_hotdog = 0, sum_bun = 0;
    vector<int> hotdogs(n);
    while (n--) {
        cin >> hotdogs[n];
        sum_hotdog += hotdogs[n];

        for (int i = sum_hotdog; i >= hotdogs[n]; i--) {
            hotdogs_dp[i] = min(hotdogs_dp[i], hotdogs_dp[i - hotdogs[n]] + 1);
        }
    }

    cin >> n;
    vector<int> buns(n);
    while (n--) {
        cin >> buns[n];
        sum_bun += buns[n];

        for (int i = sum_bun; i >= buns[n]; i--) {
            buns_dp[i] = min(buns_dp[i], buns_dp[i - buns[n]] + 1);
            ans = min(ans, hotdogs_dp[i] + buns_dp[i]);
        }
    }


    if (ans >= 4000) {
        cout << "Impossible" << endl;
    } else {
        cout << ans << endl;
    }
    

    return 0;
}