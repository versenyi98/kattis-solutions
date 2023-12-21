#include <iostream>
#define MAX_SIZE 10

using namespace std;

bool szabad[10];
int jelen[10];
int meret;

int n;
string tagok[9];
string osszeg;
string hasznalt_betuk;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return factorial(n - 1) * n;
}

int variation(int n, int k) {
    return factorial(n) / factorial(k);
}

void kovetkezo() {

    for (int i = meret - 1; i >= 0; i--) {
        szabad[jelen[i]] = true;
        for (int j = jelen[i] + 1; j < MAX_SIZE; j++) {
            if (szabad[j]) {
                jelen[i] = j;
                szabad[j] = false;
                for (int k = i + 1; k < meret; k++) {
                    for (int l = 0; l < MAX_SIZE; l++) {
                        if (szabad[l]) {
                            jelen[k] = l;
                            szabad[l] = false;
                            break;
                        }
                    }
                }
                return;
            }
        }
    }

    for (int i = 0; i < meret; i++) {
        jelen[i] = i;
        szabad[i] = false;
    }

    for (int i = meret; i < MAX_SIZE; i++) {
        szabad[i] = true;
    }
}

long long stringToNumber(string str) {

    long long return_value = 0;

    for (int i = 0; i < str.length(); i++) {
        return_value *= 10;
        return_value += jelen[hasznalt_betuk.find(str[i])];
    }

    return return_value;
}

int main() {

    meret = 2;

    while (cin >> n) {

        hasznalt_betuk = "";

        for (int i = 0; i < n - 1; i++) {
            cin >> tagok[i];
            for (int j = 0; j < tagok[i].length(); j++) {
                if (hasznalt_betuk.find(tagok[i][j]) == string::npos) {
                    hasznalt_betuk += tagok[i][j];
                }
            }
        }
        cin >> osszeg;
        for (int i = 0; i < osszeg.length(); i++) {
            if (hasznalt_betuk.find(osszeg[i]) == string::npos) {
                hasznalt_betuk += osszeg[i];
            }
        }

        meret = hasznalt_betuk.length();
        for (int i = 0; i < meret; i++) {
            jelen[i] = i;
            szabad[i] = false;
        }

        for (int i = meret; i < MAX_SIZE; i++) {
            szabad[i] = true;
        }

        int result = 0;

        for (int i = 0; i < variation(MAX_SIZE, MAX_SIZE - meret); i++) {

            long long sum = 0;
            bool con = false;

            for (int j = 0; j < n - 1; j++) {
                if (jelen[hasznalt_betuk.find(tagok[j][0])] == 0) {
                    con = true;
                    break;
                }
                sum += stringToNumber(tagok[j]);
            }

            if (con || jelen[hasznalt_betuk.find(osszeg[0])] == 0) {
                kovetkezo();
                continue;
            }

            if (sum == stringToNumber(osszeg)) {
                result++;
            }

            kovetkezo();
        }
        cout << result << endl;
    }
}