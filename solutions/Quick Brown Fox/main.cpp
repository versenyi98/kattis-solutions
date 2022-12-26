#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	string line;
	getline(cin, line);

	while (n--) {
		getline(cin, line);

		int present[26] = {0};

		for (auto c : line) {
			if (isalpha(c)) {
				if (isupper(c)) {
					present[c - 'A']++;
				} else {
					present[c - 'a']++;
				}
			}
		}

		bool first = true;
		for (int i = 0; i < 26; i++) {
			if (present[i]) continue;
			if (first) {
				first = false;
				cout << "missing ";
			}
			cout << (char)(i + 'a');
		}
		if (first) {
			cout << "pangram";
		}
		cout << endl;
	}

	return 0;
}