#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

/*
	for (int i = 0; i <= 2018; i++) {
		for (int j = 0; j <= 2018; j++) {
			if (i * i + j * j == 4072324) {
				cout << i << " " << j << endl;
			}
		}
	}
*/
	map<pair<int, int>, int> m;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		m[{a, b}]++;
	}

	int res = 0;

	for (auto i : m) {
		res += m[{i.first.first - 0, i.first.second - 2018}];
		res += m[{i.first.first - 1118, i.first.second - 1680}];
		res += m[{i.first.first - 1118, i.first.second + 1680}];
		res += m[{i.first.first - 1680, i.first.second - 1118}];
		res += m[{i.first.first - 1680, i.first.second + 1118}];
		res += m[{i.first.first - 2018, i.first.second - 0}];
	}

	cout << res << endl;

	return 0;
}