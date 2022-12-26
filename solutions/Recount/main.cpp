#include <bits/stdc++.h>

using namespace std;

int main() {

	std::ios_base::sync_with_stdio(false);

	string line;
	string maxi_person = "";
	unordered_map<string, int> m;

	int maxi = 0;
	bool runoff = false;

	while (getline(cin, line), line != "***") {
		m[line]++;

		if (m[line] == maxi) {
			runoff = true;
		}

		if (m[line] > maxi) {
			runoff = false;
			maxi_person = line;
			maxi = m[line];
		}
	}

	if (runoff) {
		cout << "Runoff!" << endl;
	} else {
		cout << maxi_person << endl;
	}

	return 0;
}