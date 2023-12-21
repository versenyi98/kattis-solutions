#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	while (test_cases--) {
		int n;
		cin >> n;

		priority_queue<int, vector<int>, less<int>> pq2;
		priority_queue<int, vector<int>, greater<int>> pq1;

		string op, t1, t2;
		int count, price;
		int last_deal = -1;

		while (n--) {
			cin >> op >> count >> t1 >> t2 >> price;

			if (op == "buy") {
				while (count--) pq2.push(price);
			} else {
				while (count--) pq1.push(price);
			}

			while (pq1.size() && pq2.size() && pq1.top() <= pq2.top()) {
				last_deal = pq1.top();
				pq1.pop();
				pq2.pop();
			}

			if (pq1.size()) {
				cout << pq1.top() << ' ';
			} else {
				cout << "- ";
			}

			if (pq2.size()) {
				cout << pq2.top() << ' ';
			} else {
				cout << "- ";
			}

			if (last_deal > 0) {
				cout << last_deal << endl;
			} else {
				cout << "-" << endl;
			}

		}
	}

	return 0;
}