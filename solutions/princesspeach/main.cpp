#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, y;
	cin >> n >> y;

	bool count[n] = {0};

	while (y--) {
		int num;
		cin >> num;

		count[num] = true;
	}

	int counter = 0;

	for (int i = 0; i < n; i++) {
		if (count[i]) {
			counter++;
			continue;
		}

		cout << i << endl;
	}
	cout << "Mario got " << counter << " of the dangerous obstacles." << endl;


	return 0;
}