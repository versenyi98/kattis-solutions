#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int tt = 1; tt <= n; tt++) {
		cout << "Case #" << tt << ": ";

		int k, l;
		cin >> k >> l;

		bool wrong = false;

		for (int i = 0; i < k; i++) {
			if (!(l & (1 << i))) {
				wrong = true;
				break;
			}
		}

		if (wrong) cout << "OFF" << endl;
		if (!wrong) cout << "ON" << endl;
	}

	return 0;
}