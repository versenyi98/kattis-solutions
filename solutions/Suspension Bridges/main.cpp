#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

double l(double a, double d) {
    return 2.0 * a * sinh(d / (2.0 * a));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double d, s;

    cin >> d >> s;

    double high = 1000000000000;
    double low = 0.0;

    while (abs(high - low) > 0.0000000001) {
        double a = (high + low) / 2.0;

        auto val1 = a + s;
        auto val2 = a * cosh(d / (2.0 * a));

        if (val1 == val2) {
            break;
        } else if (val1 < val2) {
            low = a;
        } else {
            high = a;
        }
    }

    printf("%.30f\n", l(high, d));

    return 0;
}