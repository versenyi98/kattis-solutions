#include <bits/stdc++.h>

using namespace std;

int main() {

	int N, M, n, m;
	cin >> N >> M >> n >> m;
	int arr[N][M], mask[n][m];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mask[i][j];
		}
	}

	for (int i = 0; i < N - n + 1; i++) {
		for (int j = 0; j < M - m + 1; j++) {
			int val = 0;

			for (int ii = 0; ii < n; ii++) {
				for (int jj = 0; jj < m; jj++) {
					val += (arr[i + ii][j + jj] * mask[n - ii - 1][m - jj - 1]);
				}
			}

			if (j) cout << ' ';
			cout << val;
		}
		cout << endl;
	}

	return 0;
}