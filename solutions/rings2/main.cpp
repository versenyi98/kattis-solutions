#include <bits/stdc++.h>

using namespace std;

int log(int l) {
	int r = 0;
	while (l) {
		r++;
		l /= 10;
	}

	return r;
}

int main() {

	int n, m;
	cin >> n >> m;

	int arr[n][m];
	string line[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = 0;
		}
	}

	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> line[i];
	}
	int layer = 0;
	for (int k = 1; k < 51; k++)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (line[i][j] == 'T') {
				layer = k;
				bool has_empty = false;
				has_empty = has_empty || i - 1 < 0 || (line[i - 1][j] == '.' && arr[i - 1][j] != k);
				has_empty = has_empty || i + 1 >= n || (line[i + 1][j] == '.' && arr[i + 1][j] != k);
				has_empty = has_empty || j - 1 < 0 || (line[i][j - 1] == '.' && arr[i][j - 1] != k);
				has_empty = has_empty || j + 1 >= m || (line[i][j + 1] == '.' && arr[i][j + 1] != k);

				if (has_empty) {
					arr[i][j] = k;
					line[i][j] = '.';
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]) {
				for (int k = log(arr[i][j]); k < 1 + log(layer); k++) {
					cout << '.';
				}
				cout << arr[i][j];
			} else {
				for (int k = 0; k < 1 + log(layer); k++) {
					cout << '.';
				}
			}
		}
		cout << endl;
	}

	return 0;
}