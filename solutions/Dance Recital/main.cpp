#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    uint64_t factn = 1;
    for (int i = 1; i < n + 1; i++) factn *= i;

    vector<string> v;
    vector<int> vv;
    string s;
    int cost[n][n];

    for (int i = 0; i < n; i++) {
        cin >> s; v.push_back(s);
        vv.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int c = 0;
            for (auto k : v[i]) {
                if (v[j].find(k) != string::npos) c++;
            }
            cost[i][j] = c;
            cost[j][i] = c;
        }
    }

    int mini = INT_MAX;
    for (uint64_t i = 0; i < factn; i++) {
        int sum = 0;
        for (int j = 0; j < vv.size() - 1; j++) {
            sum += cost[vv[j]][vv[j + 1]];
        }
        mini = min(mini, sum);
        next_permutation(vv.begin(), vv.end());
    }

    cout << mini << endl;
    return 0;
}