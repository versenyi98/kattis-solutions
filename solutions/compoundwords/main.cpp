#include <bits/stdc++.h>

using namespace std;

int main() {

	vector<string> v;
	set<string> s;

	string st;

	while (cin >> st) {
		v.push_back(st);
		for (int i = 0; i < v.size() - 1; i++) {
			s.insert(v[i] + st);
			s.insert(st + v[i]);
		}
	}

	for (auto i : s) cout << i << endl;

	return 0;
}