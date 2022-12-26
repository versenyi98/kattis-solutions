#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {

	std::ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<int, int> occ;
	string line;
	ost t;

	while (cin >> line) {
		if (line[0] == '#') {

			if (t.size() % 2 == 0) {
				auto res = *t.find_by_order(t.size() / 2);
				cout << res.first << endl;
				t.erase(res);
			} else {
				auto res = *t.find_by_order((t.size() + 1) / 2 - 1);
				cout << res.first << endl;
				t.erase(res);
			}
		} else {
			t.insert({stoi(line), occ[stoi(line)]++});
		}
	}

	return 0;
}