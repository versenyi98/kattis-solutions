#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    uint64_t n1, n2;

    while (cin >> n1 >> n2, n1 || n2) {

        int flag = 0;
        int counter = 0;
        while (n1 || n2) {

            if (n1 % 10 + n2 % 10 + flag >= 10) {
                counter++;
                flag = 1;
            } else {
                flag = 0;
            }

            n1 /= 10;
            n2 /= 10;
        }

        if (counter == 1) {
            cout << "1 carry operation." << endl;
        } else if (counter) {
            cout << counter << " carry operations." << endl;
        } else {
            cout << "No carry operation." << endl;
        }
    }

    return 0;
}