#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m;
	int tc = 0;
	while (cin >> n >> m, n || m) {
		if (tc++) cout << endl;
		vector<string> str;
		for (int i = 0; i < m; i++) str.push_back("");

		for (int i = 0; i < n; i++) {
			string line;
			cin >> line;

			for (int j = 0; j < m; j++) {
				str[j] += line[j];
			}
		}

		sort(str.begin(), str.end(), [] (string a, string b) {
			for (int i = 0; i < a.length(); i++) {
				if (tolower(a[i]) != tolower(b[i])) {
					return tolower(a[i]) < tolower(b[i]);
				}
			}
			return false;
		});

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << str[j][i];
			}
			cout << endl;
		}
	}

	return 0;
}