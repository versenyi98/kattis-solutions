#include <bits/stdc++.h>

using namespace std;

void recursive(const vector<int> l[100000], const vector<string>& vs, int ind) {

	for (int i = 0; i < l[ind].size(); i++) {
		if (l[ind][i] == ind) {
			cout << vs[ind];
		} else {
			recursive(l, vs, l[ind][i]);
		}
	}
}

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<string> lines;
	vector<int> l[n];

	string st;
	for (int i = 0; i < n; i++) {
		cin >> st;
		lines.push_back(st);
		l[i].push_back(i);
	}
	
	int from = 0, to;
	for (int i = 0; i < n - 1; i++) {

		cin >> from >> to;

		from--;
		to--;
		
		l[from].push_back(to);
	}
	
	recursive(l, lines, from);
	cout << endl;

	return 0;
}