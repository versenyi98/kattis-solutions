#include <bits/stdc++.h>

using namespace std;

int main() {

	string L;
	getline(cin, L); getline(cin, L);

	stack<char> ch;
	bool error = false;
	for (int i = 0; i < L.length(); i++) {
		if (L[i] == '(') {
			ch.push(L[i] + 1);
		} else if (L[i] == '[' || L[i] == '{') {
			ch.push(L[i] + 2);
		} else if (L[i] == ')' || L[i] == ']' || L[i] == '}') {
			if (ch.size() && ch.top() == L[i]) {
				ch.pop();
			} else {
				cout << L[i] << ' ' << i << endl;
				error = true;
				break;
			}
		}
	}

	if (!error) {
		cout << "ok so far" << endl;
	}

	return 0;
}