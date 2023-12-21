#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;

	string l1, l2;
	string ll1 = "", ll2 = "";
	cin >> l1 >> l2;
	int res1 = 0, res2 = 0;

	for (int i = 0; i < n; i++) {
		if (l1[i] == l2[i]) res1++;
		if (l1[i] != l2[i]) {
			ll1 += l1[i];
			ll2 += l2[i];
		}
	}

	sort(ll1.begin(), ll1.end());
	sort(ll2.begin(), ll2.end());

	int ind1 = 0, ind2 = 0;

    while (ind1 < ll1.length() && ind2 < ll2.length()) {
        if (ll1[ind1] == ll2[ind2]) {
            res2++;
            ind1++;
            ind2++;
        } else if (ll1[ind1] < ll2[ind2]) {
            ind1++;
        } else {
            ind2++;
        }
    }
	cout << res1 << " " << res2 << endl;

	return 0;
}