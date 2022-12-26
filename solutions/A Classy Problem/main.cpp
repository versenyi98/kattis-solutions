#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	int test_cases;
	cin >> test_cases;

	while (test_cases--) {
		int n;
		cin >> n;

		vector<pair<vector<int>, string>> v;
		v.resize(n);

		int max_len = 0;
		while (n) {
			n--;
			string name, class_, trash;
			cin >> name >> class_ >> trash;
			name.pop_back();


			v[n].second = name;
			vector<int> vv;

			while (class_.find('-') != string::npos) {
				string sub = class_.substr(0, class_.find('-'));
				class_ = class_.substr(class_.find('-') + 1);

				if (sub == "upper") {
					vv.push_back(1);
				} else if (sub == "middle") {
					vv.push_back(2);
				} else {
					vv.push_back(3);
				}
			}
			if (class_ == "upper") {
				vv.push_back(1);
			} else if (class_ == "middle") {
				vv.push_back(2);
			} else {
				vv.push_back(3);
			}

			v[n].first = vv;
			max_len = max(max_len, (int)vv.size());
		}

		for (int i = 0; i < v.size(); i++) {
			reverse(v[i].first.begin(), v[i].first.end());
			for (int j = v[i].first.size(); j < max_len; j++) {
				v[i].first.push_back(2);
			}
		}

		sort(v.begin(), v.end());

		for (auto i : v) {
			cout << i.second << endl;
		}
		cout << "==============================" << endl;
	}

	return 0;
}