#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

void print(int n) {
    if (n == 0) return;
    if (n % 3 == 0) {
        cout << "triple " << n / 3 << endl;
    } else if (n % 2 == 0) {
        cout << "double " << n / 2<< endl;
    } else {
        cout << "single " << n << endl;
    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<int> s;
    s.insert(0);
    for (int i = 1; i <= 20; i++) {
        s.insert(i);
        s.insert(i * 2);
        s.insert(i * 3);
    }

    int n;
    cin >> n;
    for (auto i : s) {
        for (auto j : s) {
            for (auto k : s) {
                if (i + j + k == n) {
                    print(i); print(j); print(k);
                    return 0;
                }
            }
        }
    }

    cout << "Impossible" << endl;

    return 0;
}