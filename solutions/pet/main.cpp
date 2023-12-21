#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cm = -1;
    int ci = 0;

    for (int i = 1; i <= 5; i++) {
        int sum = 0;
        for (int j = 0; j < 4; j++) {
            int n;
            cin >> n;
            sum += n;
        }
        if (sum > cm) {
            cm = sum;
            ci = i;
        }
    }

    cout << ci << ' ' << cm << endl;

    return 0;
}