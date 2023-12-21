#include <bits/stdc++.h>

using namespace std;

int main() {

    int lower = 1;
    int upper = 1000;
    int guess = (lower + upper) / 2;
    string answer;

    cout << guess << endl;
    cout.flush();

    while(cin >> answer, answer != "correct") {
        if (answer == "lower") {
            upper = guess - 1;
        } else {
            lower = guess + 1;
        }

        guess = (lower + upper) / 2;
        cout << guess << endl;
        cout.flush();
    }
}