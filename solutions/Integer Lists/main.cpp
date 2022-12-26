#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	while (test_cases--) {
		string operation;
		cin >> operation;

		bool rev = false;

		int size;
		cin >> size;

		list<int> l;
		int num;
		char trash;
		
		cin >> trash;
		for (int i = 0; i < size; i++) {
			if (i) {
				cin >> trash;
			}
			cin >> num;
			l.push_back(num);
		}
		cin >> trash;

		bool err = false;
		for (int i = 0; i < operation.length(); i++) {
			if (operation[i] == 'R') {
				rev = !rev;
			} else {
				if (l.empty()) {
					err = true;
					break;
				} else {
					size--;
					if (rev) {
						l.pop_back();
					} else {
						l.pop_front();
					}
				}
			}
		}
		if (err) {
			cout << "error" << endl;
		} else {
			if (rev) l.reverse();
			int cc = 0;
			cout << '[';
			for (auto i : l) {
				cout << i;
				if (cc++ != size - 1) cout << ',';
			}
			cout << ']' << endl;
		}
	}

	return 0;
}