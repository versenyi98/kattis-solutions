#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int res[n];
	int idx = 0;

	int current = INT_MIN;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num > current) {
			res[idx++] = num;
			current = num;
		}
	}
	cout << idx << endl;
	for (int i = 0; i < idx; i++) {
		if (i) cout << ' ';
		cout << res[i];
	}
	cout << endl;

	return 0;
}