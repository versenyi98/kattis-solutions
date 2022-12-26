#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

class Fenwick {

    public:
        Fenwick() {}
        Fenwick(int n) : sz(n), ft(vector<long long>(n)) {}

        long long rqs(int j) {
            long long sum = 0;
            while (j >= 0) {
                sum += ft[j];
                j = (j & (j + 1)) - 1;
            }
            return sum;
        }

        void update(int j, long long val) {
            while (j < sz) {
                ft[j] += val;
                j |= (j + 1);
            }
        }

        long long rqs(int i, int j) {
            return rqs(j) - rqs(i - 1);
        }

    private:
        vector<long long> ft;
        int sz;
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    int value[6];

    cin >> n >> m;
    for (int i = 0; i < 6; i++) {
        cin >> value[i];
    }

    string line;
    cin >> line;

    Fenwick fenwicks[6];

    for (int i = 0; i < 6; i++) {
        fenwicks[i] = Fenwick(n + 1);
    }

    for (int i = 0; i < n; i++) {
        fenwicks[line[i] - '1'].update(i, 1);
    }

    int opt, a, b;
    for (int i = 0; i < m; i++) {
        cin >> opt >> a >> b;
        if (opt == 1) {
            fenwicks[line[a - 1] - '1'].update(a - 1, -1);
            line[a - 1] = '0' + b;
            fenwicks[line[a - 1] - '1'].update(a - 1, +1);
        } else if (opt == 2) {
            value[a - 1] = b;
        } else {
            long long sum = 0;
            for (int j = 0; j < 6; j++) {
                sum += fenwicks[j].rqs(a - 1, b - 1) * value[j];
            }
            cout << sum << endl;
        }
    }

    return 0;
}