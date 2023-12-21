#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int counter[n + 1] = {0};
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int nn;
		cin >> nn;
		counter[nn - 1]++;
		v.push_back(nn);
	}

	if (!counter[n]) {
		cout << "Error" << endl;
		return 0;
	}


	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n + 1; i++) {
		if (counter[i] == 0) pq.push(i + 1);
	}

	int idx = 0;
	while (idx != n) {

		cout << pq.top() << endl;
		pq.pop();

		counter[v[idx++] - 1]--;
		if (counter[v[idx - 1] - 1] == 0) {
			pq.push(v[idx - 1]);
		}
	}

	return 0;
}