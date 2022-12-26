#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int actual = 1;
        int counter = 0;

        int n;
        cin >> n;
        while (n--) {
            int a;
            cin >> a;
            if (a == actual) {
                actual++;
            } else {
                counter++;
            }
        }

        cout << counter << endl;
    }

    return 0;
}