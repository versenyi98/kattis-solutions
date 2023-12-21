#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef tuple<double, int, int> tdii;
typedef pair<double, double> pdd;

class UFDS {
public:
    UFDS(int n) {
        v.resize(n);
        for (int i = 0; i < n; i++) {
            v[i] = i;
        }
    }

    void union_(int i, int j) {
        v[find_(i)] = find_(j);
    }

    int find_(int i) {
        return v[i] == i ? i : v[i] = find_(v[i]);
    }

    bool is_same_set(int i, int j) {
        return find_(i) == find_(j);
    }

private:
    vector<int> v;

};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n;
        cin >> n;

        UFDS ufds(n);

        vector<pdd> v(n);
        priority_queue<tdii, vector<tdii>, greater<tdii>> pq;

        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
            for (int j = 0; j < i; j++) {
                pq.push({hypot(v[i].first - v[j].first, v[i].second - v[j].second), i, j});
            }
        }

        double sum = 0.0;

        while (pq.size()) {
            auto [cost, a, b] = pq.top();
            pq.pop();

            if (!ufds.is_same_set(a, b)) {
                ufds.union_(a, b);
                sum += cost;
            }
        }
        cout << fixed << setprecision(2) << sum << endl;
    }

    return 0;
}