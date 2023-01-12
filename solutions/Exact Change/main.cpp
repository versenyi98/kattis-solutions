#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        vector<int> memo(50000, 200);
        memo[0] = 0;

        int target;
        cin >> target;

        int sum = 0;
        int coins;
        cin >> coins;

        int amount_paid = INT_MAX;
        int coins_paid = 0;

        while (coins--) {
            int coin;
            cin >> coin;

            if (sum <= 15000) {
                sum += coin;
            }

            for (int i = sum; i >= coin; i--) {
                memo[i] = min(memo[i], memo[i - coin] + 1);
                if (i >= target && memo[i] != 200) {
                    if (i < amount_paid) {
                        amount_paid = i;
                        coins_paid = memo[i];
                    } else if (i == amount_paid) {
                        coins_paid = min(coins_paid, memo[i]);
                    }
                }
            }
        }
        cout << amount_paid << " " << coins_paid << endl;
    }
    return 0;
}