#include <bits/stdc++.h>

using namespace std;

int main() {


	int arr[4][4];
	int rotated[4][4];
	bool changed[4][4];
	int rotation;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
			rotated[i][j] = arr[i][j];
			changed[i][j] = false;
		}
	}

	cin >> rotation;

	for (int rot = 0; rot < rotation; rot++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				rotated[3 - j][i] = arr[i][j];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				arr[i][j] = rotated[i][j];
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 0) continue;
			int new_j = j;
			for (int jj = j - 1; jj >= 0; jj--) {
				if (changed[i][jj] || (arr[i][jj] != arr[i][j] && arr[i][jj] > 0)) {
					break;
				}
				if (arr[i][jj] == arr[i][j]) {
					new_j = jj;
					arr[i][jj] *= 2;
					arr[i][j] = 0;
					changed[i][jj] = true;
					break;
				}
				if (arr[i][jj] == 0) {
					new_j = jj;
				}
			}

			if (!changed[i][new_j]) {
				swap(arr[i][new_j], arr[i][j]);
			}
		}
	}

	for (int rot = 0; rot < 4 - rotation; rot++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				rotated[3 - j][i] = arr[i][j];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				arr[i][j] = rotated[i][j];
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (j) cout << ' ';
			cout << arr[i][j];
		}
		cout << endl;
	}

	return 0;
}