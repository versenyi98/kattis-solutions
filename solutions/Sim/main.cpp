#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;
	string line;
	getline(cin, line);

	while (test_cases--) {
		getline(cin, line);

		list<char> list_;
		list<char>::iterator it = list_.begin();

		for (int i = 0; i < line.length(); i++) { 

			if (line[i] == '[') {
				it = list_.begin();
			} else if (line[i] == ']') {
				it = list_.end();
			} else if (line[i] == '<') {
				if (!list_.empty() && it != list_.begin()) {
					auto it_copy = it;
					list_.erase(--it_copy);
				}
			} else {
				list_.insert(it, line[i]);
			}
		}

		for_each(list_.begin(), list_.end(), [] (const char& ch) {
			putchar(ch);
		});
		puts("");
	}

	return 0;
}