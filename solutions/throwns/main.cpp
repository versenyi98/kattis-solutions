#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, k;
	stack<int> st;
	st.push(0);

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		string op;
		cin >> op;

		if (op == "undo") {
			int amount;
			cin >> amount;

			for (int j = 0; j < amount; j++) {
				st.pop();
			}
		} else {
			int res = stoi(op);
			res = (st.top() + res + n * 10000) % n;
			st.push(res);
		}
	}

	cout << st.top() << endl;

	return 0;
}