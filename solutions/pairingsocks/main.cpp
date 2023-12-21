#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	stack<int> st1, st2;

	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		int num;
		cin >> num;
		st1.push(num);
	}

	while (st1.size()) {
		if (st2.size() && st1.top() == st2.top()) {
			st1.pop();
			st2.pop();
			continue;
		}

		st2.push(st1.top());
		st1.pop();
	}

	if (st2.size() || st1.size()) {
		cout << "impossible" << endl;
	} else {
		cout << 2 * n << endl;
	}

	return 0;
}