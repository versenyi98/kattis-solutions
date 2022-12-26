#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	int arr[N][M];
	int sum[N][M];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			sum[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i) {
				if (j) {
					sum[i][j] = max(sum[i][j - 1] + arr[i][j], sum[i - 1][j] + arr[i][j]);
				} else {
					sum[i][j] = arr[i][j] + sum[i - 1][j];
				}
			} else {
				if (j) {
					sum[i][j] += arr[i][j] + sum[i][j - 1];
				} else {
					sum[i][j] = arr[i][j];
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (i) cout << ' ';
		cout << sum[i][M - 1];
	}
	cout << endl;

	return 0;
}