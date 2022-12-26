#include <bits/stdc++.h>

using namespace std;

int main() {

	ios_base::sync_with_stdio(true);

	int n;
	cin >> n;

	map<int, priority_queue<int>> m;


	while (n--) {
		string operation;
		cin >> operation;

		if (operation == "add") {
			int energy, gold;
			cin >> energy >> gold;
			m[energy].push(gold);
		} else {
			int energy;
			cin >> energy;
			uint64_t total_gold = 0;

			auto it = m.end();

			while (m.size()) {
				it = m.lower_bound(energy);

				if (it == m.end()) it--;

				while (it->first > energy && it != m.begin()) {
					it--;
				}

				if (it->first > energy) break;

				total_gold += it->second.top();
				energy -= it->first;
				it->second.pop();

				if (it->second.empty()) {
					m.erase(it);
				}
			}
			cout << total_gold << endl;
		}
	}

	return 0;
}