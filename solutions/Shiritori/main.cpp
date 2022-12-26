#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	unordered_set<string> s;
	string last = " ";
	string current = " ";
	int loser = -1;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> current;

		s.insert(current);

		if (s.size() != i + 1 || (i && last.back() != current.front())) {
			loser = i % 2 + 1;
			break;
		}

		last = current;
	}

	if (loser > 0) {
		cout << "Player " << loser << " lost\n";
	} else {
		cout << "Fair Game" << endl;
	}

	return 0;
}