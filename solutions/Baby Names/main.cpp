#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {

	ios_base::sync_with_stdio(false);

	ost male, female;

	int t;
	while (cin >> t) {
		if (t == 1) {
			string name;
			int gender;
			cin >> name >> gender;

			if (gender == 1) {
				male.insert(name);
			} else {
				female.insert(name);
			}
		} else if (t == 2) {
			string name;
			cin >> name;

			auto it = male.find(name);
			if (it != male.end()) male.erase(it);
			it = female.find(name);
			if (it != female.end()) female.erase(it);

		} else if (t == 3) {
			string from, to;
			int type;

			cin >> from >> to >> type;

			if (type == 1) {
				printf("%d\n", male.order_of_key(to) - male.order_of_key(from));
			}

			if (type == 2) {
				printf("%d\n", female.order_of_key(to) - female.order_of_key(from));
			}

			if (type == 0) {
				printf("%d\n", male.order_of_key(to) - male.order_of_key(from) + female.order_of_key(to) - female.order_of_key(from));
			}
		}
	}

	return 0;
}