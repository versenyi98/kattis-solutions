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
    int test_cases;
    cin >> test_cases;

    while(test_cases--) {
        vector<Point<int>> points;
        int n;
        cin >> n;

        while (n--) {
            Point<int> p;
            cin >> p.x >> p.y;
            points.push_back(p);
        }

        cout << area_of_polygon(points) << endl;
    }

    return 0;
}
