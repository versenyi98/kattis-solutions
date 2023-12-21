#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    while (cin >> n >> m >> k) {
        k -= 2;
        int arr[n][m];
        string str[n];
        for (int i = 0; i < n; i++) {
            cin >> str[i];
            string &a = str[i];
            for (int j = 0; j < m; j++) {
                if (a[j] == '*') {
                    arr[i][j] = 1;
                } else {
                    arr[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) arr[i][j] += arr[i - 1][j];
                if (j > 0) arr[i][j] += arr[i][j - 1];
                if (i > 0 && j > 0) arr[i][j] -= arr[i - 1][j - 1];
            }
        }
        int val = 0;
        int ans = 0;
        int ii, jj;
        for (int i = 1; i < n - k; i++) {
            for (int j = 1; j < m - k; j++) {
                val = arr[i + k - 1][j + k - 1] - arr[i - 1][j + k - 1] - arr[i + k - 1][j - 1] + arr[i - 1][j - 1];
                if (val > ans) {
                    ans = val;
                    ii = i - 1;
                    jj = j - 1;
                }
            }
        }
        cout << ans << endl;

        for (int i = ii; i < ii + k + 2; i++) {
            str[i][jj] = '|';
            str[i][jj + k + 1] = '|';
        }
        for (int j = jj; j < jj + k + 2; j++) {
            str[ii][j] = '-';
            str[ii + k + 1][j] = '-';
        }
        str[ii][jj] = '+';
        str[ii + k + 1][jj + k + 1] = '+';
        str[ii + k + 1][jj] = '+';
        str[ii][jj + k + 1] = '+';

        for (int i = 0; i < n; i++) {
            cout << str[i] << endl;
        }
    }

    return 0;
}