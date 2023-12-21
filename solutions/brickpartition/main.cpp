#include <bits/stdc++.h>

using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (a == 0) return b;
    return gcd(max(a, b) % min(a, b), min(a, b));
}

int main() {
    ios_base::sync_with_stdio(0);

    unsigned long long tc;
    cin >> tc;
    for (unsigned long long tt = 0; tt < tc; tt++) {
        unsigned long long n;
        cin >> n;
        char ch[n];
        unsigned long long val[n];
        unsigned long long B = 0, W = 0;
        for (unsigned long long i = 0; i < n; i++) {
            cin >> val[i] >> ch[i];
            if (ch[i] == 'B') {
                B+=val[i];
            } else {
                W+=val[i];
            }
        }
        if (W == 0|| B == 0) {
            cout << W + B << endl;
            continue;
        }
        unsigned long long gcd_ret = gcd(W, B);
        B /= gcd_ret;
        W /= gcd_ret;

        unsigned long long BB = 0, WW = 0;
        unsigned long long count = 0;

        for (unsigned long long i = 0; i < n; i++) {
            if (ch[i] == 'W') {
                if (BB % B) {
                    WW += val[i];
                } else {
                    if (WW/W < BB/B && (WW + val[i])/W >= BB/B) {
                        count++;
                    }
                    WW += val[i];
                }
            } else {
                if (WW % W) {
                    BB += val[i];
                } else {
                    if (WW/W > BB/B && (BB + val[i])/B >= WW/W) {
                        count++;
                    }
                    BB += val[i];
                }
            }
        }
        cout << count << endl;
    }
}