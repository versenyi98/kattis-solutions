#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y;

    while (cin >> x >> y) {
        int n;
        vector<int> l, u;
        vector<float> v;

        int remainder = y;

        cin >> n;
        for (int i = 0; i < n; i++) {
            int a, b;
            float c;
            cin >> a >> b >> c;

            l.push_back(a);
            u.push_back(b);

            v.push_back(c);

            remainder = remainder - b + a;
        }

        double upper = y;
        double lower = -y;

        int cc = 0;
        while (cc++ < 200000) {
            double mid = (upper + lower) / 2;
            double res = remainder * mid;

            for (int i = 0; i < n; i++) {
                res += (u[i] - l[i]) * v[i] * mid;
            }

            if (res == x) {
                upper = mid;
                break;
            }

            if (res > x) {
                upper = mid;
            } else {
                lower = mid;
            }
        }

        printf("%.10f\n", upper);
    }

    return 0;
}