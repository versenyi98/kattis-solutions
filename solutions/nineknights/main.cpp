#include <bits/stdc++.h>

using namespace std;

int main() {

	int x[] = {-2, -1, +1, +2, -2, -1, +1, +2};
	int y[] = {-1, -2, -2, -1, +1, +2, +2, +1};

	string table[5];

	for (int i = 0; i < 5; i++) {
		cin >> table[i];
	}

	bool valid = true;
	int cc = 0;
	for (int i = 0; i < 5 && valid; i++) {
		for (int j = 0; j < 5 && valid; j++) {
			if (table[i][j] == 'k') {
				cc++;
				for (int ii = 0; ii < 8 && valid; ii++) {
					if (i + x[ii] < 5 && i + x[ii] >= 0 && j + y[ii] < 5 && j + y[ii] >= 0 && table[i + x[ii]][j + y[ii]] == 'k') {
						valid = false;
					}
				}
			}
		}
	}

	valid = valid && (cc == 9);

	if (valid) {
		cout << "valid\n";
	} else {
		cout << "invalid\n";
	}

	return 0;
}