#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    while (cin >> N >> M) {
        vector<int> down, up;

        for (int i = 0; i < N / 2; i++) {
            int a;
            cin >> a; down.push_back(a);
            cin >> a; up.push_back(a);
        }

        sort(up.begin(), up.end());
        sort(down.begin(), down.end());

        int minimal = INT_MAX;
        int counter = 0;

        for (float h = 1; h <= M; h++) {
            int idx = distance(down.begin(), lower_bound(down.begin(), down.end(), h ));
            int current1 = down.size() - idx;

            idx = distance(up.begin(), lower_bound(up.begin(), up.end(), M - h + 1));
            int current2 = up.size() - idx;

            if (current1 + current2 < minimal) {
                minimal = current1 + current2;
                counter = 1;
            } else if (current1 + current2 == minimal) {
                counter++;
            }
        }

        cout << minimal << " " << counter << endl;
    }

    return 0;
}