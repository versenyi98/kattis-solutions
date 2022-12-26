#include <bits/stdc++.h>

using namespace std;

pair<int, int> new_movement(const pair<int, int>& old_movement, const char& prism) {

	pair<int, int> new_ = {old_movement.first, old_movement.second};

	if (prism == '/') {
		new_.first = -old_movement.second;
		new_.second = -old_movement.first;
	} else if (prism == '\\') {
		new_.first = old_movement.second;
		new_.second = old_movement.first;
	}

	return new_;
}

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases = 0;
	int n, m;

	while (cin >> m >> n, n || m) {
		cout << "HOUSE " << ++test_cases << endl;
		string lines[n];
		pair<int, int> pos;
		pair<int, int> movement;
		for (int i = 0; i < n; i++) {
			cin >> lines[i];
			if (lines[i].find('*') != string::npos) {
				pos = {i, lines[i].find('*')};
				if (pos.first == 0) {
					movement = {1, 0};
				} else if (pos.first == n - 1) {
					movement = {-1, 0};
				} else if (pos.second == 0) {
					movement = {0, 1};
				} else {
					movement = {0, -1};
				}
			}
		}

		while (lines[pos.first][pos.second] != 'x') {
			pos.first += movement.first;
			pos.second += movement.second;
			if (lines[pos.first][pos.second] != '.') {
				movement = new_movement(movement, lines[pos.first][pos.second]);
			}
		}

		lines[pos.first][pos.second] = '&';

		for (int i = 0; i < n; i++) {
			cout << lines[i] << endl;
		}
	}

	return 0;
}