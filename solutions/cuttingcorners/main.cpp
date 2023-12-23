#include <bits/stdc++.h>

using namespace std;

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
struct Vec {
    Vec(T x, T y) : x(x), y(y) {}
    Vec() : x(0), y(0) {}
    T x;
    T y;
};

template<typename T>
Vec<T> toVec(Point<T> a, Point<T> b) {
    return Vec<T>(b.x - a.x, b.y - a.y);
}

template<typename T>
double dot(Vec<T> a, Vec<T> b) {
    return a.x * b.x + (double)a.y * (double)b.y;
}

template<typename T>
double norm_sq(Vec<T> v) {
    return v.x * v.x + v.y * v.y;
}

template<typename T>
double angle(const Point<T>& a, const Point<T>& o, const Point<T>& b) {
    Vec<T> oa = toVec(o, a);
    Vec<T> ob = toVec(o, b);

    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

template<typename T>
void simulate_cutting(vector<Point<T>> &points) {
    while (points.size() > 3) {
        vector<double> angles;

        double min_angle = 100;
        int min_idx = -1;

        for (int i = 0; i < points.size(); i++) {
            int p = (i - 1 + points.size()) % points.size();
            int n = (i + 1) % points.size();

            angles.push_back(angle(points[p], points[i], points[n]));

            if (angles.back() < min_angle) {
                min_angle = angles.back();
                min_idx = i;
            }
        }
        int pp = (min_idx - 2 + points.size()) % points.size();
        int p  = (min_idx - 1 + points.size()) % points.size();
        int n  = (min_idx + 1) % points.size();
        int nn = (min_idx + 2) % points.size();

        if (angle(points[pp], points[p], points[n]) > min_angle && 
            angle(points[p], points[n], points[nn]) > min_angle) {
                points.erase(points.begin() + min_idx);
        } else {
            break;
        }
    }
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

        simulate_cutting(points);

        cout << points.size();
        for (auto p : points) {
            cout << ' ' << p.x << ' ' << p.y;
        }
        cout << endl;
    }
}