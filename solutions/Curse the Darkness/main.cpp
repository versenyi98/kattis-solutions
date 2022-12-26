#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9

using namespace std;

struct point {
    double x, y;

    point() {
        x = 0;
        y = 0;
    }

    point(double x_, double y_) : x(x_), y(y_) {

    }

    bool operator < (const point& other) const {
        if (fabs(x - other.x) < EPS) {
            return y < other.y;
        }
        return x < other.x;
    }

    bool operator == (const point& other) const {
        return fabs(x - other.x) < EPS && fabs(y - other.y);
    }
};

double dist(const point& a, const point& b) {
    return hypot(a.x - b.x, a.y - b.y);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        double x, y;
        cin >> x >> y;
        point pos(x, y);

        int n;
        cin >> n;

        bool good = false;
        while (n--) {
            cin >> x >> y;
            point p(x, y);
            if (dist(p, pos) <= 8.00 + EPS) {
                good = true;
            }
        }

        cout << (good ? "light a candle" : "curse the darkness") << endl;
    }

    return 0;
}