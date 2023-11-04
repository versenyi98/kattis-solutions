#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    map<char, int> m;

    cin >> s;

    for (auto c : s) {
        m[c]++;
    }

    vector<int> v;
    for (auto [key, value] : m) {
        v.push_back(value);
    }

    sort(v.begin(), v.end());

    if (v.size() <= 2) {
        cout << 0 << endl;
    } else {
        int r = accumulate(v.begin(), v.end() - 2, 0);
        cout << r << endl;
    }
}