#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	map<int, int> was_shot_before;
	int counter = 0;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (was_shot_before[num + 1]) {
			was_shot_before[num + 1]--;
		} else {
			counter++;
		}
		was_shot_before[num]++;
	}

	cout << counter << endl;

	return 0;
}