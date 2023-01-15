#include <bits/stdc++.h>

using namespace std;

int INF = 1000000000;

int n;
vector<int> distances;
vector<vector<int>> memo;

int dp(int index, int height) {
    if (index == n && height == 0) {
        return 0;
    }

    if (index == n) {
        return INF;
    }

    int& result = memo[index][height];

    if (result != -1) {
        return result;
    }
     
    result = height;
    int down = INF;
    if (height - distances[index] >= 0) {
        down = dp(index + 1, height - distances[index]);
    }

    int up = INF;
    if (height + distances[index] < 3000) {
        up = dp(index + 1, height + distances[index]);
    }

    result = max(result, min(up, down));

    return result;
}

int main() {

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        cin >> n;
        distances = vector<int>(n);
        memo = vector<vector<int>>(n);

        int distance;
        for (int i = 0; i < n; i++) {
            cin >> distance;
            distances[i] = distance;            
            
            memo[i] = vector<int>(3000, -1);
        }

        int result = dp(0, 0);
        if (result == INF) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        int height = 0;
        for (int i = 0; i < n - 1; i++) {
            if (height - distances[i] >= 0) {
                int down = memo[i + 1][height - distances[i]];
                if (down <= result) {
                    cout << "D";
                    height -= distances[i];
                    continue;
                }
            }
            if (height + distances[i] < 3000) {
                int up = memo[i+ 1][height + distances[i]];
                if (up <= result) {
                    cout << "U";
                    height += distances[i];
                    continue;
                }
            }
        }
        cout << "D" << endl;
    }
}