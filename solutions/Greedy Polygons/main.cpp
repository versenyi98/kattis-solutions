#include <bits/stdc++.h>

using namespace std;

int main() {
    int tc;
    cin >> tc;

    for (int tt = 0; tt < tc; tt++) {
        double sides, length, expansion, land_grab;
        cin >> sides >> length >> expansion >> land_grab;

        double angle = 360.0 / sides / 2.0;
        double m = length / 2.0 / tan(M_PI/180.0 * angle);
        double area_of_polygon = m * (length / 2.0) * sides;
        double area_of_spoiler = sides * expansion * land_grab * length;
        double area_of_slices = sides * pow(expansion * land_grab, 2) * M_PI / 360.0 * (180.0 - ((sides - 2) * 180.0) / sides);

        printf("%.10f\n", area_of_spoiler + area_of_slices + area_of_polygon);
    }
}