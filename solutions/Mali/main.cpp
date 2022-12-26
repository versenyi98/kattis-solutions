#include <bits/stdc++.h>

using namespace std;

int res(vector<int> a, vector<int> b) {
	int ai = 0, bi = 99;
	int result = 0;
	while (ai < 100 && bi > -1) {
		while (a[ai] == 0) {
			ai++;
			if (ai == 100) break;
		}

		while (b[bi] == 0) {
			bi--;
			if (bi < 0) break;
		}
		if (bi < 0 || ai == 100) break;

		result = max(result, ai + bi + 2);

		int occ = min(a[ai], b[bi]);
		a[ai] -= occ;
		b[bi] -= occ;
	}

	return result;
}

int main() {

	int n;
	vector<int> a(100, 0), b(100, 0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int aa, bb;
		cin >> aa >> bb;

		a[aa-1]++;
		b[bb-1]++;

		cout << res(a, b) << endl;
	}
	return 0;
}