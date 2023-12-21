#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	deque<int> front;
	deque<int> back;
	int n;
	cin >> n;
	
	while (n--) {
		string operation;
		cin >> operation;

		int number;
		cin >> number;

		if (operation == "push_back") {
			back.push_back(number);
		} else if (operation == "push_front") {
			front.push_front(number);
		} else if (operation == "push_middle") {
			if (!((front.size() + back.size()) & 1)) {
				while (front.size() > back.size()) {
					back.push_front(front.back());
					front.pop_back();
				}

				while (back.size() > front.size()) {
					front.push_back(back.front());
					back.pop_front();
				}

				front.push_back(number);
			} else {

				while ((int)front.size() - (int)back.size() > 1) {
					back.push_front(front.back());
					front.pop_back();
				}

				while (back.size() > front.size()) {
					front.push_back(back.front());
					back.pop_front();
				}
				back.push_front(number);
			} 

		} else {
			if (number >= front.size()) {
				cout << *(back.begin() + number - front.size()) << endl;
			} else {
				cout << *(front.begin() + number) << endl;
			}
		}
	}

	return 0;
}