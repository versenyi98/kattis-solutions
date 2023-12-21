#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

class UFDS {

    public:
        UFDS(int n) : parent(vector<int>(n)), left(vector<bool>(n)), right(vector<bool>(n)){
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        bool join_sets(int n, int m) {
            int pn = get_set(n);
            int pm = get_set(m);

            parent[pn] = pm;
            left[pm] = left[pm] || left[pn];
            right[pm] = right[pm] || right[pn];

            return left[pm] && right[pm];
        }

        bool is_same_set(int n, int m) {
            return get_set(n) == get_set(m);
        }

        int get_set(int n) {
            return parent[n] == n ? n : parent[n] = get_set(parent[n]);
        }

        bool has_left_and_right(int n) {
            return left[n] && right[n];
        }

    vector<int> parent;
    vector<bool> left;
    vector<bool> right;    
};


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    while (cin >> n >> m) {
        int t[n][m];

        UFDS ufds(m * n);

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for (int i = 0; i < n; i++) {
            ufds.left[i * m] = true;
            ufds.right[i * m + m - 1] = true;

            for (int j = 0; j < m; j++) {
                cin >> t[i][j];

                if (j) {
                    pq.push({max(t[i][j], t[i][j - 1]), {i * m + j - 1, i * m + j}});
                }
                if (i) {
                    pq.push({max(t[i][j], t[i - 1][j]), {i * m + j, (i - 1)  * m  + j}});
                }
            }
        }

        while (pq.size()) {
            auto top = pq.top(); pq.pop();
            if (!ufds.is_same_set(top.second.first, top.second.second)) {
                bool res = ufds.join_sets(top.second.first, top.second.second);
                if (res) {
                    cout << top.first << endl;
                    break;
                }
            }
            
        }
    }

    return 0;
}