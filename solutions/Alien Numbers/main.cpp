#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int pow(int n, int k) {
    return k == 0 ? 1 : n * pow(n, k - 1);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int nn = 0;
    while (n--) {
        cout << "Case #" << ++nn << ": ";
        string num, source, dest;
        cin >> num >> source >> dest;

        int val = 0;
        for (int i = 0; i < num.length(); i++) {
            val *= source.length();
            val += source.find(num[i]);
        }

        int val_cpy = val;
        int counter = 0;
        while (val_cpy) {
            counter++;
            val_cpy /= dest.length();
        }
        for (; counter > 0; counter--) {
            int res = val / pow(dest.length(), counter - 1);
            cout << dest[res];
            val -= res * pow(dest.length(), counter - 1);
        }
        cout << endl;
    }

    return 0;
}