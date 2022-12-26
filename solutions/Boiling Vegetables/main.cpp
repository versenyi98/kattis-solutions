#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    float ratio;
    int n;
    auto comp = [] (pair<int, int> a, pair<int, int> b) {
        return (float) a.first / (float) a.second < (float) b.first / (float) b.second;
    };
    while (cin >> ratio >> n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        float minimal = pow(10, 7);
        int w;
        for (int i = 0; i < n; i++) {
            cin >> w;
            pq.push({w, 1});
            minimal = min(minimal, w / 1.0f);
        }

        int res = 0;

        while (pq.size()) {
            auto top = pq.top();

            if (minimal / ((float)top.first / (float)top.second) >= ratio) {
                break;
            }

            pq.pop();
            pq.push({top.first, top.second + 1});

            minimal = min(minimal, (float)top.first / (float)(top.second + 1));
            res++;
        }

        cout << res << endl;
    }

    return 0;
}