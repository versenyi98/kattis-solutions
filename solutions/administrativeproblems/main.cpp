#include <bits/stdc++.h>

using namespace std;

struct triplet {
	int first;
	int second;
	int third;
};

struct action {
	int timestamp;
	string person;
	char act;
	int value = 0;
	string car = "";

	bool operator<(const action& act) const {
		return timestamp < act.timestamp;
	}
};

int main() {

	ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	while (test_cases--) {
		int cars, actions;
		cin >> cars >> actions;

		unordered_map<string, triplet> car_stats;

		string car_name;
		while (cars--) {
			triplet t;
			cin >> car_name >> t.first >> t.second >> t.third;
			car_stats[car_name] = t;
		}

		unordered_map<string, string> car_of_person;
		map<string, int> payment;

		vector<action> action_vec;

		while (actions--) {
			action a;
			cin >> a.timestamp >> a.person >> a.act;

			if (a.act == 'p') {
				cin >> a.car;
			} else {
				cin >> a.value;
			}

			action_vec.push_back(a);
		}

		sort(action_vec.begin(), action_vec.end());

		for (auto i : action_vec) {
			if (payment[i.person] == INT_MIN) {
				continue;
			}

			if ((i.act == 'p' && car_of_person[i.person] != "") || (i.act != 'p' && car_of_person[i.person] == "")) {
				payment[i.person] = INT_MIN;
				continue;
			}

			if (i.act == 'p') {
				car_of_person[i.person] = i.car;
				payment[i.person] += car_stats[i.car].second;
			}

			if (i.act == 'a') {
				payment[i.person] += ceil((car_stats[car_of_person[i.person]].first * i.value) / 100.00);
			}

			if (i.act == 'r') {
				payment[i.person] += car_stats[car_of_person[i.person]].third * i.value;
				car_of_person[i.person] = "";
			}
		}

		for (auto i : payment) {
			cout << i.first << " ";
			if (car_of_person[i.first] != "" || i.second == INT_MIN) {
				cout << "INCONSISTENT" << endl;
			} else {
				cout << i.second << endl;
			}
		}

	}

	return 0;
}