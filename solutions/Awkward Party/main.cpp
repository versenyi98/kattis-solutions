#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	map<int, int> last_one;
	int minimum = n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (last_one[num] == 0) {
			last_one[num] = i + 1;
			continue;
		}

		minimum = min(minimum, i + 1 - last_one[num]);
	}

	cout << minimum << endl;

	return 0;
}