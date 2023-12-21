#include <bits/stdc++.h>

using namespace std;

vector<pair<int, string>> sorted_commands;
map<int, int> index_of_label;
map<string, int> value_of_variable;

bool is_number(const string& s) {
	return (!isalpha(s[0]));
}

int arithmetic(stringstream& stream) {

	string o1, o2, operator_ = "";

	stream >> o1;
	int val1 = (is_number(o1) ? stoi(o1) : value_of_variable[o1]);

	if (!(stream >> operator_ >> o2)) {
		return val1;
	}

	int val2 = (is_number(o2) ? stoi(o2) : value_of_variable[o2]);

	if (operator_ == "+") {
		return val1 + val2;
	} else if (operator_ == "-") {
		return val1 - val2;
	} else if (operator_ == "*") {
		return val1 * val2;
	} else {
		return val1 / val2;
	}
}

bool condition(stringstream& stream) {

	string o1, o2, operator_;

	stream >> o1 >> operator_ >> o2;

	int val1 = (is_number(o1) ? stoi(o1) : value_of_variable[o1]);
	int val2 = (is_number(o2) ? stoi(o2) : value_of_variable[o2]);

	if (operator_ == "=") {
		return val1 == val2;
	} else if (operator_ == ">") {
		return val1 > val2;
	} else if (operator_ == "<") {
		return val1 < val2;
	} else if (operator_ == "<>") {
		return val1 != val2;
	} else if (operator_ == "<=") {
		return val1 <= val2;
	} else {
		return val1 >= val2;
	}
}

int main() {

	std::ios_base::sync_with_stdio(false);

	int label;
	string command;

	while (cin >> label && getline(cin, command)) {
		sorted_commands.push_back({label, command});
	}

	sort(sorted_commands.begin(), sorted_commands.end());

	for (int i = 0; i < sorted_commands.size(); i++) {
		index_of_label[sorted_commands[i].first] = i;
	}

	int current_index = 0;

	while (true) {

		if (current_index == sorted_commands.size()) break;

		stringstream stream;
		stream << sorted_commands[current_index].second;
		string operation;
		stream >> operation;

		if (operation == "LET") {
			string var;
			stream >> var;

			string equ;
			stream >> equ; // =

			value_of_variable[var] = arithmetic(stream);

			current_index++;
			continue;
		}

		if (operation == "IF") {
			bool result = condition(stream);
			string then, goto_;
			int l;

			stream >> then >> goto_ >> l;

			if (result) {
				current_index = index_of_label[l];
			} else {
				current_index++;
			}
			continue;
		}

		if (operation == "PRINT") {

			string result = stream.str();
			result = result.substr(result.find("PRINT ") + 6);
			if (result.back() == '"') {
				result.pop_back();
				result = result.substr(1);
				cout << result;
			} else {
				cout << value_of_variable[result];
			}

			current_index++;
			continue;
		}

		if (operation == "PRINTLN") {

			string result = stream.str();
			result = result.substr(result.find("PRINTLN ") + 8);

			if (result.back() == '"') {
				result.pop_back();
				result = result.substr(1);
				cout << result;
			} else {
				cout << value_of_variable[result];
			}

			cout << endl;
			current_index++;
			continue;
		}
	}

	return 0;
}