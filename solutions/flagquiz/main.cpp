#include <bits/stdc++.h>

using namespace std;

int main() {

	string line;
	int n;

	getline(cin, line);
	cin >> n;
	getline(cin, line);

	vector<vector<string>> v;
	vector<int> mistakes;
	while (n--) {
		vector<string> vv;
		getline(cin, line);
		size_t comma;
		while (comma = line.find(','), comma != string::npos) {
			vv.push_back(line.substr(0, comma));
			line = line.substr(comma + 1);
		}
		vv.push_back(line);
		v.push_back(vv);
		mistakes.push_back(0);
	}

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			int mistake = 0;
			for (int k = 0; k < v[j].size(); k++) {
				if (v[i][k] != v[j][k]) {
					mistake++;
				}
			}
			mistakes[i] = max(mistakes[i], mistake);
		}
	}

	int res = *min_element(mistakes.begin(), mistakes.end());

	for (int ii = 0; ii < mistakes.size(); ii++) {
		if (mistakes[ii] == res) {
			for (int i = 0; i < v[ii].size(); i++) {
				if (i) cout << ',';
				cout << v[ii][i];
			}
			cout << endl;
		}
	}

	return 0;
}