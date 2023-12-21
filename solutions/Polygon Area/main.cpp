#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct Point {
    Point(T x, T y) : x(x), y(y) {}
    Point() : x(0), y(0) {}

    T x;
    T y;
};

template<typename T>
double area_of_polygon(const vector<Point<T>> &v, string& orientation) {
    T sum1 = 0;
    T sum2 = 0;

    for (int i = 0; i < v.size(); i++) {
        sum1 += v[i].y * v[(i + 1) % v.size()].x;
        sum2 += v[i].x * v[(i + 1) % v.size()].y;
    }

    double area = (sum1 - sum2) / 2.0;    
    orientation = area < 0 ? "CCW" : "CW";

    return abs(area);
}


int main() {
    int n;

    while (cin >> n, n) {
        vector<Point<int>> v;
        while (n--) {
            Point<int> p;
            cin >> p.x >> p.y;
            v.push_back(p);
        }
        string orientation = "";
        double area = area_of_polygon(v, orientation);

        cout << fixed << setprecision(1) << orientation << " " << area << endl;
    }
}