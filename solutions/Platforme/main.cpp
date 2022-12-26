#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

struct point {
    double x, y;
    point(double a_, double b_) : x(a_), y(b_) {}
};

struct vec {
    double x, y;
    vec(double a_, double b_) : x(a_), y(b_) {}
};

vec to_vec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

int dot(vec a, vec b) {
    return a.x * b.x + a.y * b.y;
}

int norm_sq(vec a) {
    return a.x * a.x + a.y * a.y;
}

vec scale(vec v, double d) {
    return vec(v.x * d, v.y * d);
}

point translate(point p, vec v) {
    return point(p.x + v.x, p.y + v.y);
}

double dist(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

double dist_to_line_segment(point p, point a, point b) {
    vec ap = to_vec(a, p);
    vec ab = to_vec(a, b);

    double u = dot(ap, ab) / (double) norm_sq(ab);

    if (u < 0.0 || u > 1.0) return 10e9;
    return dist(p, translate(a, scale(ab, u)));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while (cin >> n) {
        vector<pair<point, point>> segments;
        vector<point> points;

        double x1, x2, y;
        for (int i = 0; i < n; i++) {
            cin >> y >> x1 >> x2;

            points.push_back(point(x1 + 0.5, y));
            points.push_back(point(x2 - 0.5, y));

            segments.push_back(make_pair(point(x1, y), point(x2, y)));
        }

        double pillars = 0.0;
        for (auto p : points) {
            double mini = 10e9;

            for (auto s : segments) {
                if (s.first.y == p.y && s.first.x < p.x && s.second.x > p.x) continue;
                if (s.first.y > p.y) continue;
                mini = min(mini, dist_to_line_segment(p, s.first, s.second));
            }

            if (mini == 10e9) {
                pillars += p.y;
            } else {
                pillars += mini;
            }
        }
        cout << (int)pillars << endl;
    }

    return 0;
}