#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

class Fenwick {
    public:
        Fenwick(int n) {
            ft.assign(n, 0);
        }

        void update(int j, int v) {
            while (j < ft.size()) {
                ft[j] += v;
                j |= (j + 1);
            }
        }

        int rqs(int j) {
            int sum = 0;
            while (j >= 0) {
                sum += ft[j];
                j = (j & j + 1) - 1;
            }
            return sum;
        }

    unordered_map<int, int> position;
    int size = 0;

    private:
        vector<int> ft;
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n, m;
        cin >> n >> m;
        Fenwick fenwick(n + m + 2);

        for (int i = m + 1; i < n + m + 1; i++) {
            fenwick.update(i, 1);
            fenwick.position[i - m - 1] = i;
        }
        fenwick.size = m;

        for (int i = 0; i < m; i++) {
            int q;
            cin >> q;

            if (i) cout << ' ';
            cout << fenwick.rqs(fenwick.position[q - 1] - 1);

            fenwick.update(fenwick.position[q - 1], -1);
            fenwick.position[q - 1] = fenwick.size--;
            fenwick.update(fenwick.position[q - 1], +1);
        }
        cout << endl;
    }

    return 0;
}