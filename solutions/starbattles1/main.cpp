#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<string> regions(10);
    vector<string> stars(10);

    map<pair<int, int>, bool> is_star;
    map<int, int> in_row, in_col, in_region;

    for (int i = 0; i < 10; i++) {
        cin >> regions[i];
    }

    for (int i = 0; i < 10; i++) {
        cin >> stars[i];
        for (int j = 0; j < 10; j++) {
            if (stars[i][j] == '*') {
                in_row[i]++;
                in_col[j]++;
                in_region[regions[i][j] - '0']++;

                for (int di = i - 1; di != i + 2; di++) {
                    for (int dj = j - 1; dj != j + 2; dj++) {
                        if (is_star[{di, dj}]) {
                            cout << "invalid" << endl;
                            return 0;
                        }
                    }
                }
                is_star[{i, j}] = true;
            }
        }
    }

    vector<int> keys;
    for (int i = 0; i < 10; i++) {
        keys.push_back(i);
    }

    if (all_of(keys.begin(), keys.end(), [in_row, in_col, in_region] (int key) {
        return in_row.at(key) == 2 && in_col.at(key) == 2 && in_region.at(key) == 2;
    })) {
        cout << "valid" << endl;
    } else {
        cout << "invalid" << endl;
    }


}