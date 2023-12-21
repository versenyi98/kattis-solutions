#include <bits/stdc++.h>

using namespace std;

int main() {

	string line;
	int tc = 0;
	while (getline(cin, line)) {
		vector<string> lines;
		lines.push_back(line);

		if (tc++) cout << endl;

		while(getline(cin, line) && line.length()) {
			lines.push_back(line);
		}

		size_t max_len = 0;
		for (string& l : lines) {
			max_len = max(max_len, l.length());
			reverse(l.begin(), l.end());
		}

		sort(lines.begin(), lines.end());

		for (string& ll : lines) {
			reverse(ll.begin(), ll.end());
			for (int i = ll.length(); i < max_len; i++) cout << ' ';
			cout << ll << endl;
		}
	}

	return 0;
}