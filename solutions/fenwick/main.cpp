#include <bits/stdc++.h>

using namespace std;

#define ll long long
typedef vector<ll> vll;

struct Fenwick {
    vll ft;
    int sz;
    Fenwick(int n) : sz(n), ft(vll(n)) {}

    ll rsq(int j) {
        ll sum = 0;
        while (j >= 0) {
            sum += ft[j];
            j = (j & (j + 1)) - 1;
        }
        return sum;
    }

    void update(int j, ll value) {
        while (j < sz) {
            ft[j] += value;
            j |= j + 1;
        }
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    char op;
    int a, b;

    cin >> n >> m;
    Fenwick* fenwick = new Fenwick(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == '+') {
            cin >> a >> b;
            fenwick->update(a, b);
        } else {
            cin >> a;
            cout << fenwick->rsq(a - 1) << '\n';
        }
    }

    return 0;
}