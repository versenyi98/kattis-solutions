#include <bits/stdc++.h>

using namespace std;

string word = "abcdefghi";

int main() {

	std::ios_base::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	for (int i = 1; i <= b; i++) {
		if (i != 1) cout << ' ';
		cout << word;
		next_permutation(word.begin(), word.end());
	}
	cout << endl;

	return 0;
}