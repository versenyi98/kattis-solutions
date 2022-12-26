#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<uint64_t> v;
    uint64_t n;

    cin >> n;

    while (cin >> n) v.push_back(n);

    sort(v.begin(), v.end());

    uint64_t sum = 0;

    for (int i = v.size() - 1; i >= 0; i -= 3) {
        if (i >= 2) sum += v[i - 2];
    }
    cout << sum << endl;

    return 0;
}