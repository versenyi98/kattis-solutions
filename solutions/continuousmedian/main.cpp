#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {

	ios_base::sync_with_stdio(false);

	uint64_t test_cases;
	cin >> test_cases;

	while (test_cases--) {
		uint64_t n;
		cin >> n;

		map<uint64_t, int> m;

		ost t;
		uint64_t sum = 0;
		while (n--) {
			uint64_t nn;
			cin >> nn;

			t.insert({nn, m[nn]++});

			if (t.size() % 2 == 0) {
				sum += ((*t.find_by_order(t.size() / 2 - 1)).first + (*t.find_by_order(t.size() / 2)).first) / 2;
			} else {
				sum += (*t.find_by_order(t.size() / 2)).first;
			}
		}
		cout << sum << endl;
	}

	return 0;
}