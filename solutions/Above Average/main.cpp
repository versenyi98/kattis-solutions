#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    cin >> t;

    while (t--) {
        int size;
        cin >> size;

        vector<int> numbers(size);
        for (int i = 0; i < size; i++) {
            cin >> numbers[i];
        }

        double avg = accumulate(numbers.begin(), numbers.end(), 0) / (double) size;
        int above_avg = count_if(numbers.begin(), numbers.end(), [avg] (int n) {
            return n > avg;
        });

        cout << fixed << setprecision(3);
        cout << (above_avg / (double)size) * 100.0 << "%" << endl;
    }

}