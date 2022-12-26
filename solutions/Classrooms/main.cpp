#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> tasks(n);

    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    multiset<int> end;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = end.lower_bound(-tasks[i].first);

        if (it == end.end()) {
            if (end.size() < m) {
                end.insert(-tasks[i].second - 1);
                ans++;
            }
        } else {
            end.erase(it);
            end.insert(-tasks[i].second - 1);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}