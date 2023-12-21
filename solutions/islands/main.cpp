#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[n];

    while (n--) {
        int data;
        cin >> data;

        int land[12];

        for (int i = 0; i < 12; i++) cin >> land[i];

        int counter = 0;

        for (int len = 1; len <= 10; len++) {
            for (int start = 1; start < 13 - len; start++) {
                int minimal = INT_MAX;
                for (int i = start; i < start + len; i++) {
                    minimal = min(minimal, land[i]);
                }
                if (land[start - 1] < minimal && land[start + len] < minimal) {
                    counter++;
                }
            }
        }
        cout << data << ' ' << counter << endl;
    }

    return 0;
}