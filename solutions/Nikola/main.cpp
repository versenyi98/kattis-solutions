#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

int n;
vector<int> cost;
vector<vector<int>> memo;

int dp(int square, int jump) {
    if (jump > n || square >= n || square < 0) return INF;
    if (memo[square][jump] != INF) return memo[square][jump];
    if (square == n - 1) return cost[n - 1];

    memo[square][jump] = cost[square];
    
    int jump_back = INF;
    int jump_forward = dp(square + jump, jump + 1);

    if (square - jump + 1 < square) {
        jump_back = dp(square - jump + 1, jump);
    }
    
    memo[square][jump] += min(jump_back, jump_forward);

    return memo[square][jump];
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;

        cost.push_back(c);
    }

    for (int i = 0; i < n; i++) {
        memo.push_back(vector<int>(n, INF));
    }

    cout << dp(0, 1) - cost[0] << endl;

    return 0;
}