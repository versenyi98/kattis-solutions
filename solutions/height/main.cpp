#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	while (test_cases--) {
		int case_num;
		cin >> case_num;
		int result = 0;

		int arr[20];
		for (int i = 0; i < 20; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < i; j++) {
				if (arr[j] > arr[i]) {
					int save = arr[i];
					for (int k = i; k > j; k--) {
						arr[k] = arr[k - 1];
					}
					arr[j] = save;

					result += i - j;
					break;
				}
			}
		}

		cout << case_num << ' ' << result << endl;
	}

	return 0;
}