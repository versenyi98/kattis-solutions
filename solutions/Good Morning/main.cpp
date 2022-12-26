#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

char telephone[4][3]  = {
	{'1', '2', '3'},
	{'4', '5', '6'},
	{'7', '8', '9'},
	{'g', '0', 'g'}
};

vector<string> values_str;
vector<int> values_int;

bool contains_(string str) {
	for (auto i : values_str) {
		if (i.compare(str) == 0) {
			return true;
		}
	}
	return false;
}

void recursion(string str, int x, int y) {

	if (x < 0 || x >= 4 || y < 0 || y >= 3 || telephone[x][y] == 'g') return;
	cout << str + telephone[x][y] << " ";
	if (!contains_(str + telephone[x][y])) values_str.push_back(str + telephone[x][y]);
 	if (!contains_(str)) values_str.push_back(str);
 	if (str.length() == 3) return;

	recursion(str + telephone[x][y], x, y);	// 
	recursion(str, x + 1, y);	// -
	recursion(str + telephone[x][y], x + 1, y);	//12
	recursion(str, x, y + 1);	// -
	recursion(str + telephone[x][y], x, y + 1);	//1
	recursion(str, x + 1, y + 1);
	recursion(str + telephone[x][y], x + 1, y + 1);

}

int main() {

/*
	recursion("", 0, 0);

	for (auto i : values_str) {
		values_int.push_back(atoi(i.c_str()));
	}
	sort(values_int.begin(), values_int.end());

	for (auto i : values_int) {
		cout << i  <<  ", " << endl;
	}
	cout << values_int.size() << endl;

*/	

	int nums[500] {
		1, 
		2, 
		3, 
		4, 
		5, 
		6, 
		7, 
		8, 
		9, 
		10, 
		11, 
		12, 
		13, 
		14, 
		15, 
		16, 
		17, 
		18, 
		19, 
		20, 
		22, 
		23, 
		25, 
		26, 
		28, 
		29, 
		33, 
		36, 
		39, 
		40, 
		44, 
		45, 
		46, 
		47, 
		48, 
		49, 
		50, 
		55, 
		56, 
		58, 
		59, 
		66, 
		69, 
		70, 
		77, 
		78, 
		79, 
		80, 
		88, 
		89, 
		99, 
		100, 
		110, 
		111, 
		112, 
		113, 
		114, 
		115, 
		116, 
		117, 
		118, 
		119, 
		120, 
		122, 
		123, 
		125, 
		126, 
		128, 
		129, 
		133, 
		136, 
		139, 
		140, 
		144, 
		145, 
		146, 
		147, 
		148, 
		149, 
		150, 
		155, 
		156, 
		158, 
		159, 
		166, 
		169, 
		170, 
		177, 
		178, 
		179, 
		180, 
		188, 
		189, 
		199, 
		200,
		99999,
	};

	long long lines;
	cin >> lines;

	int num;
	for (long long i = 0; i < lines; i++) {
		int save = 0;
		cin >> num;
		for (int j = 0; j < 500; j++) {
			if (abs(nums[j] - num) < abs(num - save)) {
				save = nums[j];
			} else {
				cout << save << endl;
				break;
			}
		}
	}

}