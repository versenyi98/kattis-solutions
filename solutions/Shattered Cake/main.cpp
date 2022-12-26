#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    unsigned long long int N, W, L;

    while (cin >> W) {
        cin >> N;

        unsigned long long int sum = 0, t1, t2;

        for (int i = 0; i < N; i++) {
            cin >> t1 >> t2;
            sum += t1 * t2;
        }

        cout << sum / W << endl;
    }
}