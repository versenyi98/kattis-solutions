#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    while (cin >> n >> m) {
        vector<int> times(n);
        vector<int> tasks(m);

        for (int i = 0; i < n; i++) cin >> times[i];
        for (int i = 0; i < m; i++) cin >> tasks[i];

        sort(times.begin(), times.end());
        sort(tasks.begin(), tasks.end());

        int idx = 0, idx2 = 0;

        int counter = 0;
        while (idx < times.size() && idx2 < tasks.size()) {
            if (times[idx] <= tasks[idx2]) {
                counter++;
                idx++;
            }
            idx2++;
        }
        cout << counter << endl;
    }

    return 0;
}