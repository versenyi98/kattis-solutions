#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d;

    while (cin >> n >> d, n || d) {
        printf("%d %d / %d\n", n / d, n % d, d);
    }

    return 0;
}