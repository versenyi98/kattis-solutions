#include <bits/stdc++.h>

using namespace std;

int total_cats = 0;

struct cat {

	int arrived;
	int infection;
	string name;

	bool operator< (const cat& d) const {
		if (infection != d.infection) return infection > d.infection;
		return arrived < d.arrived;
	}
};

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	set<cat> cats;
	map<string, pair<int, int>> old_value;

	while (n--) {
		int operation;
		cin >> operation;

		if (operation == 0) {
			cat d;
			string name;
			int infection;
			cin >> name >> infection;

			d.arrived = total_cats++;
			d.infection = infection;
			d.name = name;

			cats.insert(d);
			old_value[name] = {total_cats - 1, infection};

		} else if (operation == 1) {
			string name;
			int infection;
			cin >> name >> infection;

			cat d;
			d.name = name;
			d.infection = old_value[name].second;
			d.arrived = old_value[name].first;

			auto it = cats.find(d);
			auto old = *it;
			cats.erase(it);
			old.infection += infection;
			cats.insert(old);

			old_value[name].second = old.infection;
		} else if (operation == 2) {
			string name;
			cin >> name;

			cat d;
			d.name = name;
			d.arrived = old_value[name].first;
			d.infection = old_value[name].second;

			cats.erase(cats.find(d));
		} else {
			if (cats.empty()) {
				cout << "The clinic is empty" << endl;
			} else {
				cout << (*cats.begin()).name << endl;
			}
		}
	}

	return 0;
}