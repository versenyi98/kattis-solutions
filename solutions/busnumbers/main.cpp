#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	int arr[1000] = {0};

	cin >> n;

	while (n--) {
		int num;
		cin >> num;

		arr[num - 1] = 1;
	}

	bool first = true;

	for (int i = 0; i < 1000; i++) {
		if (arr[i]) {
			int last = i;
			for (int j = last; j < 1000; j++) {
				if (!arr[j]) break;
				last = j;
			}

			if (!first) cout << ' ';
			first = false;

			if (last - i <= 1) {
				cout << i + 1;
			} else {
				cout << i + 1 << '-' << last + 1;
				i = last;
			}
		}
	}

	cout << endl;

	return 0;
}