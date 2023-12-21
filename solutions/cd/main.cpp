#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m;

	while (scanf("%d %d", &n, &m), n || m) {
		unordered_set<int> s;

		int number;
		for (int i = 0; i < n + m; i++) {
			scanf("%d", &number);
			s.insert(number);
		}

		printf("%lu\n", n + m - s.size());
	}

	return 0;
}