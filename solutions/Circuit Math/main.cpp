#include <bits/stdc++.h>

using namespace std;

int main() {

	map<char, bool> m;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		m['A' + i] = (c == 'T');
	}

	stack<bool> st;

	char operand;
	while (cin >> operand) {
		if (isalpha(operand)) {
			st.push(m[operand]);
		} else if (operand == '-') {
			auto top = st.top();
			st.pop();
			st.push(!top);
		} else {
			auto top1 = st.top();
			st.pop();
			auto top2 = st.top();
			st.pop();

			if (operand == '+') st.push(top1 || top2);
			if (operand == '*') st.push(top1 && top2);
		}
	}

	cout << (st.top() ? 'T' : 'F') << endl;
	return 0;
}