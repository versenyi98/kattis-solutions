#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        int len, num;
        cin >> len >> num;

        int earliest = INT_MIN;
        int latest = INT_MIN;

        for (int i = 0; i < num; i++) {
            int point;
            cin >> point;
            earliest = max(earliest, min(point, len - point));
            latest = max(latest, max(point, len - point));
        }

        cout << earliest << ' ' << latest << endl;
    }

    return 0;
}