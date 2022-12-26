#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc = 0;
    int n;
    while (cin >> n, n) {
        if (tc++) cout << endl;
        vector<int> v1, v11, v2;
        map<int, int> m;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            v1.push_back(a);
            v11.push_back(a);
        }

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            v2.push_back(a);
        }

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for (int i = 0; i < n; i++) {
            m[v1[i]] = v2[i];
        }

        for (int i = 0; i < n; i++) {
            cout << m[v11[i]] << endl;
        }
    }


    return 0;
}