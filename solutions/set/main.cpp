#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

bool eq(char a, char b, char c) {
    return a == b && b == c;
}

bool di(char a, char b, char c) {
    return a != b && a != c && b != c;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string cards[12];

    for (int i = 0; i < 12; i++) {
        cin >> cards[i];
    }

    int cc = 0;

    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            for (int k = j + 1; k < 12; k++) {
                int c = 0;
                for (int l = 0; l < 4; l++) {
                    if (eq(cards[i][l], cards[j][l], cards[k][l]) || di(cards[i][l], cards[j][l], cards[k][l])) {
                        c++;
                    }
                }
                if (c == 4) {
                    cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                    cc++;
                }
            }
        }
    }

    if (!cc) cout << "no sets" << endl;

    return 0;
}