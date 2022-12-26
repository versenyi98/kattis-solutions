#include <iostream>
#include <map>

using namespace std;
map<string, int> m;
int n;

int main() {

	cin >> n;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;
		m[str]++;
	}
	int counter = 0;
	for (int i = 0; i < n; i++) {
		cin >> str;
		m[str]--;
		if (m[str] >= 0) {
			counter++;
		}
	}
	cout << counter << endl;
}
