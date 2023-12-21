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
    double res = (double)a.x * (double)b.y - (double)a.y * (double)b.x;
    return res;
}

template<typename T>
bool ccw(Point<T> p, Point<T> q, Point<T> r) {
    double res = cross(toVec(p, q), toVec(p, r));
    return res > EPS;
}

template<typename T>
bool collinear(Point<T> p, Point<T> q, Point<T> r) {
    double res = fabs(cross(toVec(p, q), toVec(p, r)));
    return res < EPS;
}

template<typename T>
vector<Point<T>> andrew_monotone_chain(vector<Point<T>> points) {
    sort(begin(points), end(points));

    auto last = unique(begin(points), end(points));
    points.erase(last, end(points));

    int n = points.size();
    int k = 0;
    vector<Point<int>> convex_hull(n * 2);


    for (int i = 0; i < n; i++) {
        while (k >= 2 && !(ccw(convex_hull[k - 2], convex_hull[k - 1], points[i]) || collinear(convex_hull[k - 2], convex_hull[k - 1], points[i]))) {
            k--;
        }
        convex_hull[k++] = points[i];
    }

    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && !(ccw(convex_hull[k - 2], convex_hull[k - 1], points[i]) || collinear(convex_hull[k - 2], convex_hull[k - 1], points[i]))) {
            k--;
        }
        convex_hull[k++] = points[i];
    }

    convex_hull.resize(k);

    if (convex_hull.size() > 1 && convex_hull[0] == convex_hull.back()) {
        convex_hull.pop_back();
    }

    return convex_hull;
}


int main() {
    int n;
    vector<Point<int>> points;
    
    cin >> n;
    while (n--) {
        Point<int> p;
        char ch;
        cin >> p.x >> p.y >> ch;
        if (ch == 'Y') {
            points.push_back(p);
        }
    }

    auto result = andrew_monotone_chain(points);

    cout << result.size() << endl;
    for (Point p : result) {
        cout << p.x << " " << p.y << endl;
    }
}