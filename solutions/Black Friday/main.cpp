#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int occ[6] = {0};
    int pos[6] = {0};

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        occ[m - 1]++;
        pos[m - 1] = i + 1;
    }

    for (int i = 5; i >= 0; i--) {
        if (occ[i] == 1) {
            cout << pos[i] << endl;
            return 0;
        }
    }

    cout << "none" << endl;

    return 0;
}