#include <bits/stdc++.h>

using namespace std;

int main() {

	int arr[365] = {0};

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int from, to;
		cin >> from >> to;

		for (int j = from - 1; j <= to - 1; j++) {
			arr[j] = 1;
		}
	}

	int count = 0;
	for (int i = 0; i < 365; i++) {
		if (arr[i]) count++;
	}

	cout << count << endl;

	return 0;
}