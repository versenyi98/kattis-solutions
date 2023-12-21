#include <iostream>
#include <cmath>

using namespace std;

long long n, num;

int main() {

    cin >> n;
    while (n--) {
        cin >> num;

        if (num > 1 && num % 2 == 1) {
            cout << num << " = " << num / 2 << " + " <<  num / 2 + 1 << endl;
            continue;
        }

        int shortest_len = 1000000000;
        int start = -1;

        for (int i = 2; i <= sqrt(num); i++) {

            if (num % i == 0) {
                if ((num / i) % 2 == 0 && i % 2 == 0) continue;
                int pt = (i % 2 == 0) ? num / i : i;
                int ps = num / pt;

                if (ps - pt / 2 > 0 && pt < shortest_len) {
                    shortest_len = pt;
                    start = ps - pt / 2;
                } 
                
                if (pt / 2 - ps + 1 > 0 && ps * 2 < shortest_len) {
                    shortest_len = ps * 2;
                    start = pt / 2 - ps + 1;
                }
            }
        }

        if (start == -1) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        cout << num << " = ";
        for (int i = start; i < start + shortest_len; i++) {
            if (i != start) cout << " + ";
            cout << i;
        }
        cout << endl;
    }
}