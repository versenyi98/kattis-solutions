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
        int n, nn;
        cin >> n;
        nn = n;

        int arr[n] = {0};
        int sub[n] = {0};

        int size = 0;

        while (true) {

            for (int j = size; j >= 1; j--) {
                arr[j] = arr[j - 1];
            }
            arr[0] = n;
            size++;

            for (int i = 0; i < n; i++) {
                int save = arr[size - 1];
                for (int j = size - 1; j >= 1; j--) {
                    arr[j] = arr[j - 1];
                }
                arr[0] = save;
            }
            n--;
            if (n == 0) break;
        }

        for (int i = 0; i < size; i++) {
            if (i) cout << ' ';
            cout << arr[i];
        }
        cout << endl;
    }

    return 0;
}