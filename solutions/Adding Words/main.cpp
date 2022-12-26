#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	string line;

	unordered_map<string, int> my_value_is;
	unordered_map<string, bool> does_my_value_exist;
	unordered_map<int, string> my_name_is;
	unordered_map<int, bool> does_my_name_exist;

	while (getline(cin, line)) {
		stringstream sstream;

		string operation;

		sstream << line;
		sstream >> operation;

		if (operation == "clear") {
			my_value_is.clear();
			does_my_value_exist.clear();
			my_name_is.clear();
			does_my_name_exist.clear();
		} else if (operation == "def") {
			string name;
			int value;

			sstream >> name >> value;

			if (does_my_value_exist[name]) {
				does_my_name_exist[my_value_is[name]] = false;
			}

			my_name_is[value] = name;
			my_value_is[name] = value;

			does_my_value_exist[name] = true;
			does_my_name_exist[value] = true;
		} else {
			int sum = 0;
			bool wrong = false;
			string operand, operator_ = "+";

			while (sstream >> operand) {
				wrong = !does_my_value_exist[operand] || wrong;
				sum = sum + (operator_ == "+" ? my_value_is[operand] : -1 * my_value_is[operand]);
				sstream >> operator_;

				cout << operand << ' ' << operator_ << ' ';
				if (operator_ == "=") break;
			}

			if (wrong || !does_my_name_exist[sum]) {
				cout << "unknown" << endl;
			} else {
				cout << my_name_is[sum] << endl;
			}
		}
	}

	return 0;
}