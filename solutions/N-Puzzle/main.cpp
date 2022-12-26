#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string correct[4] = {"ABCD", "EFGH", "IJKL", "MNO."};
    string current[4];

    for (int i = 0; i < 4; i++) {
        cin >> current[i];
    }

    int sum = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                for (int l = 0; l < 4; l++) {
                    if (current[i][j] == correct[k][l] && current[i][j] != '.') {
                        sum += abs(i - k) + abs(j - l);
                    }
                }
            }
        }
    }

    cout << sum<< endl;

    return 0;
}