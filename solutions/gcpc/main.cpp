#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

struct team {
	int id = 0, point = 0, pen = 0;

	bool operator< (const team& t) const {
		if (point == t.point) {
			if (pen == t.pen) {
				return id < t.id;
			}
			return pen < t.pen;
		}
		return point > t.point;
	}
};

int main() {

	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<int, team> m;
	tree<team, null_type, less<team>, rb_tree_tag, tree_order_statistics_node_update> t;

	int nn, mm;
	cin >> nn >> mm;

	for (int i = 0; i < mm; i++) {
		int tid, pen;
		cin >> tid >> pen;

		team tt = m[tid];

		tt.id = tid;
		tt.pen += pen;
		tt.point++;

		m[tid] = tt;

		tt.point--;
		tt.pen -= pen;

		t.insert(m[tid]);
		if (tt.point) t.erase(t.find(tt));

		if (m.find(1) == m.end()) {
			cout << t.size() + 1 << endl;
		} else {
			cout << t.order_of_key(m[1]) + 1 << endl;
		}

	}

	return 0;
}