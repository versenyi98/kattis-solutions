#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int arr[n] = {0};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;

			arr[i] |= num;
			arr[j] |= num;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i) cout << ' ';
		cout << arr[i];
	}
	cout << endl;

	return 0;
}