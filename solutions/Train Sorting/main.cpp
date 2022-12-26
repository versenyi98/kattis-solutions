#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, tt;
    cin >> tt;

    for (int t = 0; t < tt; t++) {
        cin >> n;

        int value;
        vector<int> values, asc, desc;
        for (int i = 0; i < n; i++) {
            cin >> value;
            values.push_back(value);
            asc.push_back(1);
            desc.push_back(1);
        }

        int mm = 0;
        for (int i = asc.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < asc.size(); j++) {
                if (values[i] < values[j]) {
                    asc[i] = max(asc[i], asc[j] + 1);
                } else {
                    desc[i] = max(desc[i], desc[j] + 1);
                }
            }
        }
        for (int i = 0; i < asc.size(); i++) mm = max(mm, asc[i] + desc[i] - 1);
        cout << mm << endl;
    }
    return 0;
}
