#include <bits/stdc++.h>

using namespace std;

int main() {

	set<uint64_t> divisors;
	uint64_t n;
	cin >> n;
	for (uint64_t i = 0; i * i <= n; i++) {
		if (n % (i + 1) == 0) {
			divisors.insert(i);
			divisors.insert(n / (i + 1) - 1);
		}
	}

	uint64_t f = 0;
	for (auto i : divisors) {
		if (f++) cout << ' ';
		cout << i;
	}
	cout << endl;

	return 0;
}