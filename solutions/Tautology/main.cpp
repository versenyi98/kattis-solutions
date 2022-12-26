#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

map<char, bool> modell;
int pos = 0;
string str;

bool processed() {

    if (str[pos] >= 'p' && str[pos] <= 't') {
        pos++;
        return modell[str[pos - 1]];
    }

    if (str[pos] == 'N') {
        pos++;
        return !processed();
    }

    if (str[pos] == 'K') {
        pos++;
        bool val1 = processed();
        bool val2 = processed();
        return val1 && val2;
    }

    if (str[pos] == 'A') {
        pos++;
        bool val1 = processed();
        bool val2 = processed();
        return val1 || val2;
    }

    if (str[pos] == 'E') {
        pos++;
        bool val1 = processed();
        bool val2 = processed();
        return val1 == val2;
    }

    if (str[pos] == 'C') {
        pos++;
        bool val1 = processed();
        bool val2 = processed();
        return !val1 || val2;
    }

    return false;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (cin >> str, str != "0") {
        bool taut = true;
        for (int p = 0; p < 2 && taut; p++) {
            for (int q = 0; q < 2 && taut; q++) {
                for (int r = 0; r < 2 && taut; r++) {
                    for (int s = 0; s < 2 && taut; s++) {
                        for (int t = 0; t < 2 && taut; t++) {
                            modell['p'] = p;
                            modell['q'] = q;
                            modell['r'] = r;
                            modell['s'] = s;
                            modell['t'] = t;
                            pos = 0;
                            taut = processed();
                        }
                    }
                }
            }
        }
        if (!taut) {
            cout << "not" << endl;
        } else {
            cout << "tautology" << endl;
        }
    }

    return 0;
}