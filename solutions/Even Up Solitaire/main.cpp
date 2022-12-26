#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	stack<int> s;

	while (n--) {
		int num;
		cin >> num;

		if (s.size() && !((s.top() + num) & 1)) {
			s.pop();
		} else {
			s.push(num);
		}
	}

	cout << s.size() << endl;

	return 0;
}