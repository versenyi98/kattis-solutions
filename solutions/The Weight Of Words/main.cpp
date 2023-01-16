#include <bits/stdc++.h>

using namespace std;

int INF = 1000000000;
int n, w;
vector<vector<int>> memo;

int dp(int idx, int weight) {

    if (idx == 0 && weight == 0) {
        return 0;
    }

    if (idx == 0 || weight < 0) {
        return INF;
    }

    if (memo[idx][weight] != -1) {
        return memo[idx][weight];
    }

    memo[idx][weight] = INF;

    for (int i = 1; i <= 26; i++) {
        memo[idx][weight] = min(memo[idx][weight], dp(idx - 1, weight - i));
    }

    return memo[idx][weight];
}

int main() {

    cin >> n >> w;
    
    if (26 * n < w || n > w) {
        cout << "impossible" << endl;
        return 0;
    }

    memo = vector<vector<int>>(n + 1);
    for (int i = 0; i < n + 1; i++) {
        memo[i] = vector<int>(w + 1, -1);
    }
    memo[0][0] = 0;

    int res = dp(n, w);

    for (int i = n; i > 0; i--) {
        for (int j = 1; j <= 26; j++) {
            if (memo[i - 1][w - j] == 0) {
                w -= j;
                cout << char('a' + j - 1);
                break;
            }
        }
    }

    return 0;
}