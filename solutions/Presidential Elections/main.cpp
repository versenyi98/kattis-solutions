#include <bits/stdc++.h>

using namespace std;

int D, C, F, U;

vector<int> delegates;
vector<int> costs;

vector<vector<int>> memo;

int total_delegates = 0;
int already_won = 0;
int INF = 1000000000;
int bin_search(int lower, int upper, int total) {
    if (lower > upper) return 0;
    int cfed = (lower + upper) / 2;
    int ccon = total - cfed;

    int res = C - F + ccon - cfed;
    if (res == 1 || res == 2) {
        return ccon;
    }
    if (res > 0) {
        return bin_search(cfed + 1, upper, total);
    } else {
        return bin_search(lower, cfed - 1, total);
    }
}

int dp(int idx, int delegates_won, int delegates_left) {
    int remaining = total_delegates - delegates_won - already_won;
    if (remaining < delegates_won + already_won) {
        return 0;
    }
    if (idx == delegates.size()) {
        return INF;
    }

    if (memo[idx][delegates_won] != -1) {
        return memo[idx][delegates_won];
    }
    int dp1 = dp(idx + 1, delegates_won, delegates_left - delegates[idx]);
    int dp2 = dp(idx + 1, delegates_won + delegates[idx], delegates_left - delegates[idx]);

    memo[idx][delegates_won] = min(dp1, dp2 + costs[idx]);
    return memo[idx][delegates_won];
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int can_be_convinced = 0;
    for (int i = 0; i < n; i++) {
        cin >> D >> C >> F >> U;

        total_delegates += D;

        int diff = F - C;
        if (diff >= U) {
            continue; // cannot win
        }

        if (-diff > U) {
            already_won += D;
            continue; // already won
        }

        costs.push_back(bin_search(0, U, U));
        delegates.push_back(D);
        can_be_convinced += D;
    }

    memo = vector<vector<int>>(delegates.size());
    for (int i = 0; i < delegates.size(); i++) {
        memo[i] = vector<int>(can_be_convinced + 1, -1);
    }

    int minimum = dp(0, 0, can_be_convinced);
    if (minimum >= INF) {
        cout << "impossible" << endl;
    } else {
        cout << minimum << endl;
    }

    return 0;
}