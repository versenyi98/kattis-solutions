#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	uint64_t n;
	cin >> n;

	set<uint64_t> s;
	uint64_t cost[1 + n] = {0};
	uint64_t sum = 0;

	uint64_t number = 0;
	for (uint64_t i = 0; i < n ; i++) {
		cin >> number;
		s.insert(number);

		if (i == 0) {
			cout << 0 << endl;
			continue;
		}

		auto left = s.find(number);
		auto right = s.find(number);

		if (left != s.begin()) {
			left--;
			cost[number] = max(cost[number], cost[*left] + 1);
		}

		if (right != s.end()) {
			right++;
			if (right != s.end()) {
				cost[number] = max(cost[number], cost[*right] + 1);
			}
		}
		sum += cost[number];
		cout << sum << endl;
	}

	return 0;
}