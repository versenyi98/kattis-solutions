#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;

    while (cin >> a >> b) {

        while (a.length() && b.length() && a.back() == b.back()) {
            a.pop_back();
            b.pop_back();
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        while (a.length() && b.length() && a.back() == b.back()) {
            a.pop_back();
            b.pop_back();
        }

        cout << b.length() << endl;
    }

    return 0;
}