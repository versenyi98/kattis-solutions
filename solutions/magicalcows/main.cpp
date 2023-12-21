#include <bits/stdc++.h>

using namespace std;

vector<uint64_t> doubles;

uint64_t maxi = 0;
uint64_t C, N, M;

int main() {

    cin >> C >> N >> M;

    for (uint64_t i = 0; i < N; i++) {
        uint64_t temp;
        cin >> temp;
        uint64_t day = 0;
        while (temp <= C) {
            day++;
            temp *= 2;
        }
        doubles.push_back(day);
    }

    for (uint64_t i = 0; i < M; i++) {
        int q;
        cin >> q;

        uint64_t res = 0;
        for (auto j : doubles) {
            if (j > q) {
                res++;
            } else {
                res += pow(2, q - j + 1);
            }
        }
        cout << res << endl;
    }
}