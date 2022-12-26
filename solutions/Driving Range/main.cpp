#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef tuple<int, int, int> tiii;

class UFDS {
public:
    UFDS(int n) {
        v.resize(n);
        for (int i = 0; i < n; i++) {
            v[i] = i;
        }
        size_of_forest = n;
    }

    void union_(int i, int j) {
        int fi = find_(v[i]);
        int fj = find_(v[j]);

        v[fi] = fj;
        size_of_forest--;
    }

    int find_(int n) {
        return n == v[n] ? n : v[n] = find_(v[n]);
    }

    bool is_same_set(int i, int j) {
        return find_(i) == find_(j);
    }

    int get_forest_size() {
        return size_of_forest;
    }

private:
    vector<int> v;
    int size_of_forest;
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    while (cin >> n >> m) {
        UFDS ufds(n);
        priority_queue<tiii, vector<tiii>, greater<tiii>> pq;

        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            pq.push({c, a, b});
        }
        int solution = 0;
        while (pq.size()) {
            auto [a, b, c] = pq.top();
            pq.pop();

            if (!ufds.is_same_set(b, c)) {
                ufds.union_(b, c);
                solution = a;
            }
        }

        if (ufds.get_forest_size() == 1) {
            cout << solution << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}