#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

template<typename T>
struct Vec {
    Vec(T x, T y) : x(x), y(y) {}
    Vec() : x(0), y(0) {}
    T x;
    T y;
};

template<typename T>
struct Point {
    Point(T x, T y) : x(x), y(y) {}
    Point() : x(0), y(0) {}
    T x;
    T y;

    bool operator<(const Point<T>& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }

    bool operator==(const Point<T>& p) const {
        return x == p.x and y == p.y;
    }
};

template<typename T>
Vec<T> toVec(Point<T> a, Point<T> b) {
    return Vec(b.x - a.x, b.y - a.y);
}

template<typename T>
double cross(Vec<T> a, Vec<T> b) {
    double res = a.x * (double)b.y - a.y * (double)b.x;
    return res;
}

template<typename T>
bool ccw(Point<T> p, Point<T> q, Point<T> r) {
    double res = cross(toVec(p, q), toVec(p, r));
    return res > EPS;
}

template<typename T>
vector<Point<T>> andrew_monotone_chain(vector<Point<T>> points) {
    int n = points.size();
    int k = 0;

    vector<Point<int>> convex_hull(n * 2);
    sort(begin(points), end(points));

    for (int i = 0; i < n; i++) {
        while (k >= 2 && !ccw(convex_hull[k - 2], convex_hull[k - 1], points[i])) {
            k--;
        }
        convex_hull[k++] = points[i];
    }

    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && !ccw(convex_hull[k - 2], convex_hull[k - 1], points[i])) {
            k--;
        }
        convex_hull[k++] = points[i];
    }

    convex_hull.resize(k);
    return convex_hull;
}

template<typename T>
double area_of_polygon(const vector<Point<T>> &v) {
    T sum1 = 0;
    T sum2 = 0;

    for (int i = 0; i < v.size(); i++) {
        sum1 += v[i].x * v[(i + 1) % v.size()].y;
        sum2 += v[i].y * v[(i + 1) % v.size()].x;
    }

    return abs(sum1 - sum2) / 2.0;
}

int main() {
    int n;
    while (cin >> n, n) {
        vector<Point<int>> points;

        while (n--) {
            Point<int> p;
            cin >> p.x >> p.y;
            points.push_back(p);
        }

        cout << fixed << setprecision(1) << area_of_polygon(andrew_monotone_chain(points)) << endl;
    }
}