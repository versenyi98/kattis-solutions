#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;

	while (cin >> n, n) {

		string operation;
		int a, b;
		bool unknown[32];
		bool value[32];

		for (int i = 0; i < 32; i++) {
			unknown[i] = true;
		}

		for (int i = 0; i < n; i++) {
			cin >> operation >> a;

			if (operation == "SET") {
				unknown[a] = false;
				value[a] = true;
			} else if (operation == "CLEAR") {
				unknown[a] = false;
				value[a] = false;
			} else {
				cin >> b;
				if (operation == "AND") {
					if ((!unknown[a] && !value[a]) || (!unknown[b] && !value[b])) {
						value[a] = false;
						unknown[a] = false;
					} else {
						unknown[a] = unknown[a] || unknown[b];
						value[a] = value[a] && value[b];
					}
				} else {
					if ((!unknown[a] && value[a]) || (!unknown[b] && value[b])) {
						value[a] = true;
						unknown[a] = false;
					} else {
						unknown[a] = unknown[a] || unknown[b];
						value[a] = value[a] && value[b];
					}
				}
			}
		}

		for (int i = 31; i >= 0; i--) {
			if (unknown[i]) {
				cout << '?';
			} else {
				cout << std::noboolalpha << value[i];
			}
		}
		cout << endl;

	}

	return 0;
}