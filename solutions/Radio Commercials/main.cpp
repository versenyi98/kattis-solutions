#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, p;
    cin >> n >> p;

    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum = a - p + sum;
        ans = max(sum, ans);
        if (sum < 0) sum = 0;
    }
    cout << ans << endl;

    return 0;
}