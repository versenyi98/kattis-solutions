#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	map<string, set<string>> who_said;
	map<string, int> times_words_said;
	set<string> persons;

	string line;
	getline(cin, line);

	while (n--) {

		getline(cin, line);

		stringstream sstream;
		sstream << line;

		string person, word;
		sstream >> person;

		persons.insert(person);

		while (sstream >> word) {
			who_said[word].insert(person);
			times_words_said[word]++;
		}
	}

	vector<pair<int, string>> v;

	for (auto i : who_said) {
		if (i.second.size() == persons.size()) v.push_back({times_words_said[i.first], i.first});
	}

	sort(v.begin(), v.end(), [] (pair<int, string> a, pair<int, string> b) {
		if (a.first == b.first) {
			return a.second < b.second;
		}
		return a.first > b.first;
	});

	if (v.size()) {
		for (auto i : v) {
			cout << i.second << endl;
		}
	} else {
		cout << "ALL CLEAR" << endl;
	}

	return 0;
}