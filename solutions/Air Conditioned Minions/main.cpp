#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    while (cin >> n) {
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;

            v.push_back({a, b});
        }

        sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });


        int res = 1;
        int cap = v[0].second;

        for (int i = 1; i < v.size(); i++) {
            if (cap < v[i].first) {
                res++;
                cap = v[i].second;
            }
        }

        cout << res << endl;
    }

    return 0;
}