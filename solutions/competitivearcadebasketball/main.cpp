#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n, p, m;
	cin >> n >> p >> m;
	unordered_map<string, int> mm;
	vector<string> winners;

	string name;
	int point;
	for (int i = 0; i < n; i++) {
		cin >> name;
		mm[name] = 0;
	}

	for (int i = 0; i < m; i++) {
		cin >> name >> point;
		mm[name] += point;
		if (mm[name] >= p && mm[name] - point < p) winners.push_back(name);
	}

	if (winners.empty()) {
		cout << "No winner!\n";
	} else {
		for (auto i : winners) {
			cout << i << " wins!\n";
		}
	}

	return 0;
}