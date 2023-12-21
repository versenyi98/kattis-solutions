#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    int sum = 0;

    if (n % 2 == 1) {
        cout << "still running" << endl;
    } else {
        int a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            
            if (i % 2 == 0) {
                sum -= a;
            } else {
                sum += a;
            }
        }
        cout << sum << endl;
    }

    return 0;
}