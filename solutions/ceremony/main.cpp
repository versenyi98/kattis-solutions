#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int>& v, int i) {

    if (i == v.size()) {
        return 0;
    }

    return min(solve(v, i + 1) + 1, v[i]);
}


int main() {
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(begin(v), end(v), greater<int>());
    cout << solve(v, 0) << endl;
}