#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    while (cin >> n >> m) {
        vector<int> arr = {0, n};
        int wall;
        set<int> res = {n};

        while (m--) {
            cin >> wall;
            for (auto i : arr) {
                res.insert(abs(wall - i));
            }
            arr.push_back(wall);
        }

        bool first = true;
        for (auto i : res) {
            if (!first) cout << " ";
            first = false;
            cout << i;
        }
        cout << endl;
    }

    return 0;
}