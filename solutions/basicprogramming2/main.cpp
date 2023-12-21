#include <bits/stdc++.h>

using namespace std;

int main() {

	int64_t n, t;
	cin >> n >> t;

	vector<int64_t> arr;
	map<int64_t, bool> m;
	map<int64_t, int64_t> occ;
	int64_t num;
	int64_t maxi = 0;
	int64_t maxi_ins = 0;

	for (int64_t i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
		m[num] = true;
		occ[num]++;

		maxi = max(occ[num], maxi);
		if (maxi == occ[num]) {
			maxi_ins = num;
		}
	}

	sort(arr.begin(), arr.end());

	if (t == 1) {
		bool res = false;
		for (int64_t i = 0; i < n && !res; i++) {
			res = m[7777 - arr[i]];
		}

		if (res) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	} else if (t == 2) {
		if (unique(arr.begin(), arr.end()) != arr.end()) {
			cout << "Contains duplicate" << endl;
		} else {
			cout << "Unique" << endl;
		}
	} else if (t == 3) {
		if (maxi > n / 2) {
			cout << maxi_ins << endl;
		} else {
			cout << -1 << endl;
		}
	} else if (t == 4) {
		if (n % 2 == 1) {
			cout << arr[n / 2] << endl;
		} else {
			cout << arr[n / 2 - 1] << ' ' << arr[n / 2] << endl;
		}
	} else if (t == 5) {
		int64_t p = 0;
		for (auto num : arr) {
			if (num >= 100 && num <= 999) {
				if (p++) cout << ' ';
				cout << num;
			}
		}
		cout << endl;
	}

	return 0;
}