#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    uint8_t arr[257];
    for (int i = 0; i < 256; i++) {
        arr[(uint8_t)(i ^ (i << 1))] = i;
    }

    int n;
    int byte;
    cin >> n;

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cin >> byte;
        cout << (int)arr[byte];
    }
    cout << endl;

    return 0;
}