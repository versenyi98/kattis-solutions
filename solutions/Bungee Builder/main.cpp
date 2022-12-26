#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int maxi = 0;
	int n;
	stack<int> st;
	stack<int> index_;

	cin >> n;

	int max_fall = INT_MIN;
	int current_max = INT_MIN;

	for (int i = 0; i < n; i++) {
		int nn;
		cin >> nn;

		current_max = max(current_max, nn);

		if (current_max == nn) {
			int first = -1;
			int maxi = INT_MIN;
			int mini = INT_MAX;

			while (st.size()) {
				mini = min(st.top(), mini);
				maxi = max(st.top(), maxi);

				first = index_.top();

				st.pop();
				index_.pop();
			}

			if (i - first > 1) {
				maxi = min(nn, maxi);
				max_fall = max(max_fall, maxi - mini);
			}
		}
		st.push(nn);
		index_.push(i);
	}

	{
		int current_max = INT_MIN;
		int current_min = INT_MAX;

		while (st.size()) {
			if (st.top() >= current_max) {
				if (current_min != INT_MAX) {
					max_fall = max(max_fall, current_max - current_min);
				}
				current_max = st.top();
				current_min = INT_MAX;
			} else {
				current_min = min(st.top(), current_min);
			}
			index_.pop();
			st.pop();
		}
	}
	if (max_fall < 0) {
		cout << 0 << endl;
	} else {
		cout << max_fall << endl;
	}

	return 0;
}