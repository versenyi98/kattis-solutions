#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int factorial(int n) {
    return n ? factorial(n - 1) * n : 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s, ss;
    cin >> s;
    ss = s;

    int diff = INT_MAX;
    for (int i = 0; i < factorial(s.length()); i++) {
        next_permutation(ss.begin(), ss.end());
        int d;
        if(d = stoi(ss) - stoi(s), d <= 0) continue;
        diff = min(diff, d);
    }

    cout << (diff == INT_MAX ? 0 : stoi(s) + diff) << endl;

    return 0;
}