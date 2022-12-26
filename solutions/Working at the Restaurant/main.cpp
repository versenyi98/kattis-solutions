#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	int test_cases = 0;
	while (cin >> n, n) {
		if (test_cases++) cout << endl;

		string operation;
		int amount;
		int s1 = 0;
		int s2 = 0;

		for (int i = 0; i < n; i++) {
			cin >> operation >> amount;

			if (operation == "DROP") {
				cout << "DROP 1 " << amount << endl;
				s1 += amount;
			} else {
				if (s2) {
					int val = min(s2, amount);
					cout << "TAKE 2 " << val << endl;
					s2 -= val;
					amount -= val;
				}

				if (amount) {
					cout << "MOVE 1->2 " << s1 << endl;
					s2 += s1;
					s1 = 0;
					cout << "TAKE 2 " << amount << endl;
					s2 -= amount;
				}
			}
		}
	}

	return 0;
}