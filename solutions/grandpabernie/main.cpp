#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n, q;
	vector<pair<string, int>> v;
	map<pair<string, int>, int> m;

	string country;
	int year;

	cin >> n;

	while (n--) {
		cin >> country >> year;
		v.push_back({country, year});
	}

	sort(v.begin(), v.end());

	int th = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i && v[i - 1].first != v[i].first) {
			th = 1;
		} else {
			th++;
		}

		m[{v[i].first, th}] = v[i].second;
	}

	cin >> q;
	while (q--) {
		cin >> country >> year;
		cout << m[{country, year}] << endl;
	}

	return 0;
}