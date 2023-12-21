#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

struct point {
    double x, y;
    point(): x(0.0), y(0.0) {}
    point(double x_, double y_): x(x_), y(y_) {}
};

double dist(const point &a, const point &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, t;
    cin >> n >> t;

    point prev_act, current_act;
    point gps_point, prev_gps_point;

    int prev_time, current_time;
    int gps_time;
    double x, y;

    cin >> x >> y >> prev_time;
    gps_time = 1;

    prev_act = point(x, y);
    gps_point = prev_act;
    prev_gps_point = prev_act;

    double actual_dist = 0.0;
    double gps_dist = 0.0;

    for (int i = 1; i < n; i++) {
        cin >> x >> y >> current_time;
        current_act = point(x, y);

        actual_dist += dist(current_act, prev_act);

        double dx = (current_act.x - prev_act.x) / (current_time - prev_time);
        double dy = (current_act.y - prev_act.y) / (current_time - prev_time);

        for (; gps_time <= current_time; gps_time++) {
            gps_point.x += dx;
            gps_point.y += dy;

            if (gps_time % t == 0) {
                gps_dist += dist(gps_point, prev_gps_point);
                prev_gps_point = gps_point;
            }
        }

        prev_act = current_act;
        prev_time = current_time;
    }

    gps_dist += dist(current_act, prev_gps_point);

    cout << setprecision(18) << ((actual_dist - gps_dist) * 100 / actual_dist) << endl;
    return 0;
}