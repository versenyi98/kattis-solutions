#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int d;
    cin >> d;

    vector<int> v(d);
    for (int i = 0; i < d; i++) cin >> v[i];

    uint64_t num_of_stocks = 0;
    uint64_t current_money = 100;

    for (int i = 0; i < d - 1; i++) {
        // buy and sell
        if (v[i] < v[i + 1]) {
            int new_n = current_money / v[i];
            if (new_n + num_of_stocks >= 100000) {
                new_n = 100000 - num_of_stocks;
            }
            current_money -= new_n * v[i];
            num_of_stocks += new_n;
            current_money += num_of_stocks * v[i + 1];
            num_of_stocks = 0;
        }
    }
    cout << current_money << endl;

    return 0;
}