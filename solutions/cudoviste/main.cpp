#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    while (cin >> n >> m) {
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        int r[5] = {0};

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                int cc = 0;
                bool building = false;
                for (int di = 0; di < 2; di++) {
                    for (int dj = 0; dj < 2; dj++) {
                        building = building || s[i + di][j + dj] == '#';
                        cc += (s[i + di][j + dj] != '.');
                    }
                }
                if (building) continue;
                r[cc]++;
            }
        }
        for (int i = 0; i < 5; i++) cout << r[i] << endl << flush;
    }

    return 0;
}