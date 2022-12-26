#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	string line;

	while (getline(cin, line)) {
		int sum = 0;
		for (auto c : line) sum += c - '0';

		if (sum % line.length() != 0) {
			printf("%s: invalid # of balls\n", line.c_str());
			continue;
		}

		int balls = sum / line.length();
		bool wrong = false;

		// when will the balls fall down
		priority_queue<int, vector<int>, greater<int>> pq;

		for (int i = 0; i < line.length() * 100; i++) {
			// if a ball falls down at i-th moment and it should be in
			// the air for 0 beats it will fall down again -> 2 ball 1 beat
			if (line[i % line.length()] == '0') {
				if (pq.size() && pq.top() == i) {
					wrong = true;
				}
			} else {
				// if we have balls which were never thrown and
				// the next ball falls down later throw a new ball
				if (balls > 0 && (pq.empty() || pq.top() > i)) {
					balls--;
					pq.push(i + line[i % line.length()] - '0');
					continue;
				}

				// if the ball falls down at the i-th moment and
				// there is another ball which falls down at this
				// moment, the pattern must be invalid

				// if there is no ball falling down at the moment
				// it should be invalid (throw a ball at every beat,
				// catch at most 1 at every beat)
				if (pq.size()) {
					if (pq.top() == i) {
						pq.pop();
						wrong = pq.size() && pq.top() == i;
					} else {
						wrong = true;
					}
				}

				pq.push(i + line[i % line.length()] - '0');
			}
		}

		if (wrong) {
			printf("%s: invalid pattern\n", line.c_str());
		} else {
			printf("%s: valid with %d balls\n", line.c_str(), sum / line.length());
		}
	}

	return 0;
}