#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	vector<string> attributes;
	{
		string attr;
		getline(cin, attr);

		size_t pos;

		while (pos = attr.find(' '), pos != string::npos) {
			attributes.push_back(attr.substr(0, pos));
			attr = attr.substr(pos + 1);
		}
		attributes.push_back(attr);
	}

	vector<map<string, string>> v;
	{
		int n;
		cin >> n;

		while (n--) {
			map<string, string> m;

			for (auto i : attributes) {
				cin >> m[i];
			}

			v.push_back(m);
		}
	}

	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			if (i) cout << endl;
			string option;
			cin >> option;

			stable_sort(v.begin(), v.end(), [option] (map<string, string> m1, map<string, string> m2) {
				return m1[option] < m2[option];
			});

			for (int k = 0; k < attributes.size(); k++) {
				if (k) cout << ' ';
				cout << attributes[k];
			}
			cout << endl;

			for (auto j : v) {
				for (int k = 0; k < attributes.size(); k++) {
					if (k) cout << ' ';
					cout << j[attributes[k]];
				}
				cout << endl;
			}
		}
	}

	return 0;
}