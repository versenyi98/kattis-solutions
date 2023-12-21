#include <bits/stdc++.h>

using namespace std;

int n, q, max_query = 0;
vector<vector<int>> memo;
vector<int> costs;
vector<int> queries;
vector<vector<int>> visited;

int dp(int idx, int rem) {
    if (idx >= n) {
        return INT_MIN;
    }
    if (rem < 0) {
        return INT_MIN;
    }
    if (rem == 0) {
        memo[idx][rem] = 0;
        visited[idx][rem] = 1;
        return 0;
    }

    if (memo[idx][rem] != -1) {
        return memo[idx][rem];
    }

    int buy = dp(idx, rem - costs[idx]);
    int stall = dp(idx + 1, rem);
 
    if (buy < 0 && stall < 0) {
        memo[idx][rem] = -2;
    } else {
        memo[idx][rem] = max(buy + 1, stall);
    }

    if (buy >= 0) {
        visited[idx][rem] += visited[idx][rem - costs[idx]];
    }
    if (stall >= 0) {
        visited[idx][rem] += visited[idx + 1][rem];
    }

    return memo[idx][rem];
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    costs = vector<int>(n);
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    cin >> q;
    queries = vector<int>(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
        max_query = max(max_query, queries[i]);
    }

    memo = vector<vector<int>>(n);
    visited = vector<vector<int>>(n);
    for (int i = 0; i < n; i++) {
        memo[i] = vector<int>(max_query + 1, -1);
        visited[i] = vector<int>(max_query + 1, 0);
    }

    for (int i = 0; i < q; i++) {
        int query = queries[i]; 
        dp(0, query);
        if (memo[0][query] < 0) {
            cout << "Impossible" << endl;
        } else {
            int idx = 0;
            vector<int> indexes;
            bool buy;
            bool stall;
            while (idx != n && query != 0) {
                buy = query - costs[idx] >= 0 && memo[idx][query - costs[idx]] >= 0;
                stall = idx + 1 != n && memo[idx + 1][query] >= 0;
                if (buy && stall) break;
                if (stall) {
                    idx++;
                    continue;
                }
                query -= costs[idx];
                indexes.push_back(idx + 1);
            }

            if (buy && stall) {
                cout << "Ambiguous" << endl;
            } else {
                for (auto index: indexes) {
                    cout << index << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}