#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

double dist(pair<double, double> a, pair<double, double> b) {
    pair<double, double> diff;
    diff.first = a.first - b.first;
    diff.second = a.second - b.second;

    return sqrt(pow(diff.first, 2) + pow(diff.second, 2));
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int l, w, n, r;

    while (cin >> l >> w >> n >> r) {

        bool good_to_go = false;

        pair<double, double> centers[] = {{-l / 2.0, 0}, {l / 2.0, 0}, {0, w / 2.0}, {0, -w / 2.0}};
        pair<double, double> locations[n];

        for (int i = 0; i < n; i++) {
            cin >> locations[i].first >> locations[i].second;
        }

        for (int i = 0; i < n && !good_to_go; i++) {
            bool b[4] = {false, false, false, false};
            int counter = 0;
            for (int ii = 0; ii < 4; ii++) {
                bool val = b[ii] || dist(centers[ii], locations[i]) <= r;
                if (val && val != b[ii]) counter++;
                b[ii] = val;
            }
            if (counter == 4) {
                good_to_go = true;
                cout << 1 << endl;
            }
        }

        for (int i = 0; i < n && !good_to_go; i++) {
            for (int j = i + 1; j < n && !good_to_go; j++) {
                bool b[4] = {false, false, false, false};
                int counter = 0;
                for (int ii = 0; ii < 4; ii++) {
                    bool val = b[ii] || dist(centers[ii], locations[i]) <= r || dist(centers[ii], locations[j]) <= r;
                    if (val && val != b[ii]) counter++;
                    b[ii] = val;
                }
                if (counter == 4) {
                    good_to_go = true;
                    cout << 2 << endl;
                }
            }
        }

        for (int i = 0; i < n && !good_to_go; i++) {
            for (int j = i + 1; j < n && !good_to_go; j++) {
                for (int k = j + 1; k < n && !good_to_go; k++) {
                    bool b[4] = {false, false, false, false};
                    int counter = 0;
                    for (int ii = 0; ii < 4; ii++) {
                        bool val = b[ii] || dist(centers[ii], locations[i]) <= r || dist(centers[ii], locations[j]) <= r || dist(centers[ii], locations[k]) <= r;
                        if (val && val != b[ii]) counter++;
                        b[ii] = val;
                    }
                    if (counter == 4) {
                        good_to_go = true;
                        cout << 3 << endl;
                    }
                }
            }
        }

        for (int i = 0; i < n && !good_to_go; i++) {
            for (int j = i + 1; j < n && !good_to_go; j++) {
                for (int k = j + 1; k < n && !good_to_go; k++) {
                    for (int l = k + 1; k < n && !good_to_go; k++) {
                        bool b[4] = {false, false, false, false};
                        int counter = 0;
                        for (int ii = 0; ii < 4; ii++) {
                            bool val = b[ii] || dist(centers[ii], locations[i]) <= r || dist(centers[ii], locations[j]) <= r || dist(centers[ii], locations[k]) <= r  || dist(centers[ii], locations[l]) <= r;
                            if (val && val != b[ii]) counter++;
                            b[ii] = val;
                        }
                        if (counter == 4) {
                            good_to_go = true;
                            cout << 4 << endl;
                        }
                    }
                }
            }
        }

        if (!good_to_go) {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}