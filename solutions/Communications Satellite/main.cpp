#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef tuple<int, int, int> tiii;
typedef tuple<double, int, int> tdii;

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

    int n;
    cin >> n;
    vector<tiii> v(n);
    priority_queue<tdii, vector<tdii>, greater<tdii>> pq;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[i] = {a, b, c};
        for (int j = 0; j < i; j++) {
            pq.push({hypot(get<0>(v[i]) - get<0>(v[j]), get<1>(v[i]) - get<1>(v[j])) - get<2>(v[i]) - get<2>(v[j]), i, j});
        }
    }

    UFDS ufds(n);

    double sum = 0.0;
    while (pq.size()) {
        auto [cost, a, b] = pq.top();
        pq.pop();
        if (!ufds.is_same_set(a, b)) {
            ufds.union_(a, b);
            sum += cost;
        }
    }

    cout << fixed << setprecision(30) << sum << endl;

    return 0;
}