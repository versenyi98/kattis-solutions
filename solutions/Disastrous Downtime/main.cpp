#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n, k;
	map<int, int> event;
	int max_event = 0;
	int counter = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		event[num]++;
		event[num + 1000]--;
	}

	for (auto i : event) {
		counter += i.second;
		max_event = max(max_event, counter);
	}

	printf("%d\n", (int)std::ceil((double) max_event / k));

	return 0;
}