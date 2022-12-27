#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<int> cost;
vector<int> weight;
vector<vector<int>> memo;
int cap, n;

int dp(int idx, int rem) {
    if (idx == n || rem == 0) {
        return 0;
    }

    if (memo[idx][rem] != -1) {
        return memo[idx][rem];
    }

    if (rem - weight[idx] < 0) {
        memo[idx][rem] = dp(idx + 1, rem);
    } else {
        memo[idx][rem] = max(dp(idx + 1, rem), dp(idx + 1, rem - weight[idx]) + cost[idx]);
    }

    return memo[idx][rem];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> cap >> n) {
        cost = vector<int>(n);
        weight = vector<int>(n);        

        memo = vector<vector<int>>(n);

        for (int i = 0; i < n; i++) {
            cin >> cost[i];
            cin >> weight[i];

            memo[i] = vector<int>(cap + 1, -1);
        }

        int best = dp(0, cap);
        vector<int> indexes;

        for (int i = 0; i < n; i++) {
            if (best == cost[i]) {
                indexes.push_back(i);
                break;
            } else if (cap - weight[i] >= 0 && best - cost[i] == memo[i + 1][cap - weight[i]]) {
                best -= cost[i];
                cap -= weight[i];
                indexes.push_back(i);
            }
        }
        cout << indexes.size() << endl;
        for (auto index : indexes) {
            cout << index << " ";
        }
        cout << endl;

    }

    return 0;
}