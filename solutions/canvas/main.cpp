#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    for (int t = 0; t < test_cases; t++) {
        int n;
        cin >> n;
        int64_t res = 0;

        priority_queue<int64_t, vector<int64_t>, greater<int64_t>> pq;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            pq.push(a);
        }

        while (pq.size() >= 2) {
            auto current = pq.top();
            pq.pop();
            current += pq.top();
            pq.pop();
            res += current;
            pq.push(current);
        }
        cout << res << endl;

    }

    return 0;
}