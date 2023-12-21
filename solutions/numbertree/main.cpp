#include <bits/stdc++.h>

using namespace std;

uint64_t pow(int n, int k) {
	if (k == 0) return 1;
	return n * pow(n, k - 1);
}

int main() {

	int n;
	string line = "";

	cin >> n;
	cin >> line;

	int res = 1;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == 'L') {
			res *= 2;
		} else {
			res *= 2;
			res++;
		}
	}
	cout << pow(2, n + 1) - res << endl;

	return 0;
}