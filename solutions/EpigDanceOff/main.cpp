#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	string lines[n];

	for (int i = 0; i < n; i++) {
		cin >> lines[i];
	}

	int point = 0;

	bool dance = false;
	for (int i = 0; i < k; i++) {
		bool empty = true;
		for (int j = 0; j < n && empty; j++) {
			if (lines[j][i] != '_') {
				empty = false;
				dance = true;
			}
		}

		if (empty && dance) {
			point++;
			dance = false;
		}
	}

	cout << point + 1 << endl;

	return 0;
}