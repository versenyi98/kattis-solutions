#include <iostream>
#include <cmath>

using namespace std;

int lines, boxes;

int main() {

    while(cin >> lines >> boxes, lines != -1) {
        int towns[lines];

        int maximum = 0;
        int minimum = 1;

        for (int i = 0; i < lines; i++) {
            cin >> towns[i];
            maximum = max(maximum, towns[i]);
        }

        int return_value = (maximum + minimum) / 2;
        while (maximum >= minimum) {
            int middle_value = (maximum + minimum) / 2;

            int boxes_ = 0;

            for (int i = 0; i < lines; i++) {
                boxes_ += towns[i] / middle_value + ((towns[i] % middle_value) ? 1 : 0);
            }

            if (boxes >= boxes_) {
                maximum = middle_value - 1, return_value = middle_value;
            } else {
                minimum = middle_value + 1;
            }
        }
        cout << return_value << endl;
    }
}