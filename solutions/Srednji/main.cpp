#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int N, B;

int main() {

	cin >> N >> B;

	int b_pos;

	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];

		if (v[i] == B) b_pos = i;
	}

	map<int, uint64_t> m;
	int diff = 0;
	m[0] = 1;

	for (int i = b_pos + 1; i < N; i++) {
		if (v[i] > B) {
			diff++;
		} else {
			diff--;
		}
		m[diff]++;
	}
	uint64_t sol = m[0];
	diff = 0;
	for (int i = b_pos - 1; i >= 0; i--) {
		if (v[i] > B) {
			diff++;
		} else {
			diff--;
		}

		sol += m[-diff];
	}

	cout << sol << endl;

	return 0;
}