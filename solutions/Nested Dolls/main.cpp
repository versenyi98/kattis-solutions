#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

vector<pair<int, int>> dolls;
vector<int> second;
int n;

vector<int> lis_second;
int lis_size;

int result;

void lis_F(int i) {

    int j = lower_bound(lis_second.begin(), lis_second.begin() + lis_size, second[i] + 1) - lis_second.begin();

    if (j == lis_size) {
        lis_second[j] = second[i];
        lis_size++;
    } else if (lis_second[i] <= second[j]) {
        lis_second[j] = second[i];
    }

    result = max(j, result);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    for (int tt = 0; tt < tc; tt++) {
        cin >> n;

        result = 0;
        lis_size = 0;

        dolls.resize(n);
        lis_second.assign(n, 0);
        second.clear();

        for (int i = 0; i < n; i++) {
            cin >> dolls[i].first >> dolls[i].second;
        }

        sort(dolls.begin(), dolls.end(), [] (pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first;
        });

        for (auto i : dolls) {
            second.push_back(i.second);
        }

        for (int i = 0; i < n; i++) {
            lis_F(i);
        }

        if (n == 0) {
            cout << 0 << endl;
            continue;
        }

        cout << result + 1  << endl;
    }
}