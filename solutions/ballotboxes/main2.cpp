#include <bits/stdc++.h>
#define endl "\n";

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n, m;

    while (scanf("%d %d", &n, &m)) {

        if (n < 0 || m < 0) break;
        priority_queue<tuple<double, int, int>> pq;

        for (int i = 0; i < n; i++, m--) {
            int a;
            scanf("%d", &a);
            pq.push({a, a, 1});
        }

        while (m--) {
            auto [ratio, num, box] = pq.top();
            pq.pop();
            pq.push({num / (box + 1.0), num, box + 1});
        }

        auto [ratio, num, box] = pq.top();
        if (num % box == 0) {
            printf("%d\n", num / box);;
        } else {
            printf("%d\n", num / box + 1);;
        }

        auto top = pq.top();
    }

    return 0;
}