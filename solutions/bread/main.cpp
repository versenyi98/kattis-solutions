#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	scanf("%d", &n);

	int arr[n], exc[n], pos[n], final_pos[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		arr[i]--;
		pos[arr[i]] = i;
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &exc[i]);
		exc[i]--;
		arr[pos[exc[i]]] = i;
		final_pos[i] = pos[exc[i]];
		exc[i] = i;
	}

	for (int i = 0; i < n - 2; i++) {
		if (final_pos[i] - i == 0) continue;
		if (final_pos[i] - i == 1) {
			int a1 = arr[final_pos[i] - 1];
			int a2 = arr[final_pos[i]];
			int a3 = arr[final_pos[i] + 1];

			arr[final_pos[a1]] = a2;
			arr[final_pos[a2]] = a3;
			arr[final_pos[a3]] = a1;

			final_pos[a2] = i;
			final_pos[a3] = i + 1;
			final_pos[a1] = i + 2;
			continue;
		}
		if (final_pos[i] - i == 2) {
			int a1 = arr[final_pos[i] - 2];
			int a2 = arr[final_pos[i] - 1];
			int a3 = arr[final_pos[i]];

			arr[final_pos[a1]] = a3;
			arr[final_pos[a2]] = a1;
			arr[final_pos[a3]] = a2;

			final_pos[a3] = i;
			final_pos[a2] = i + 2;
			final_pos[a1] = i + 1;
			continue;
		}

		int final_pos_i = final_pos[i];
		int final_pos_i1 = final_pos_i - 1;
		int final_pos_i2 = final_pos_i - 2;

		int data_i = arr[i];
		int data_fin = arr[final_pos_i];
		int data_fin1 = arr[final_pos_i1];
		int data_fin2 = arr[final_pos_i2];

		swap(arr[i], arr[final_pos_i]);
		swap(final_pos[data_i], final_pos[data_fin]);

		swap(arr[final_pos_i1], arr[final_pos_i2]);
		swap(final_pos[data_fin1], final_pos[data_fin2]);

	}

	if (arr[n - 1] == n - 1) {
		cout << "Possible" << endl;
	} else {
		cout << "Impossible" << endl;
	}

	return 0;
}
