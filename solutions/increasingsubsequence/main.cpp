#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<int> A, p;

void print_LIS(int i) {
    if (p[i] == -1) {
        printf("%d", A[i]);
    } else {
        print_LIS(p[i]);
        printf(" %d", A[i]);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while (cin >> n, n) {
        int k = 0, lis_end = 0;
        A.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        p.assign(n, -1);

        vector<int> L(n, 0), L_id(n, 0);

        for (int i = 0; i < n; i++) {
            int pos = lower_bound(L.begin(), L.begin() + k, A[i]) - L.begin();

            L[pos] = A[i];
            L_id[pos] = i;
            p[i] = pos ? L_id[pos - 1] : -1;

            if (pos == k) {
                k = pos + 1;
                lis_end = i;
            } else if (pos == k - 1) {
                lis_end = i;
            }
        }
        printf("%d ", k);
        print_LIS(lis_end);
        printf("\n");

    }

    return 0;
}