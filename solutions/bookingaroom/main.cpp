#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	int counter[n] = {0};

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;

		counter[num - 1]++;
	}

	bool late = true;

	for (int i = 0; i < n; i++) {
		if (!counter[i]) {
			cout << i + 1 << endl;
			late = false;
			break;
		}
	}

	if (late) cout << "too late" << endl;

	return 0;
}