#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	string line;
	cin >> line;

	int cc[4] = {0};

	for (auto c : line) {
		if (isupper(c)) {
			cc[2]++;
		} else if (islower(c)) {
			cc[1]++;
		} else if (c == '_') {
			cc[0]++;
		} else {
			cc[3]++;
		}
	}

	for (int i = 0; i < 4; i++) {
		printf("%.32f\n", (double)cc[i] / (double)line.length());
	}

	return 0;
}