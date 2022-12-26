#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int cases;

	while (cin >> cases && cases) {
		map<vector<int>, int> counter;
		int maximum = 0;

		for (int i = 0; i < cases; i++) {
			vector<int> v;
			int tmp;

			for (int j = 0; j < 5; j++) {
				cin >> tmp;
				v.push_back(tmp);
			}
			sort(v.begin(), v.end());

			maximum = max(maximum, ++counter[v]);

		}

		int res = 0;

		for (auto i : counter) {
			if (i.second == maximum) res += maximum;
		}

		cout << res << endl;
	}


	return 0;
}