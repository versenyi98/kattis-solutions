#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    while (cin >> input) {
        vector<pair<int, int>> v;
        stack<int> opening;

        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '(') {
                opening.push(i);
            } else if (input[i] == ')') {
                int top = opening.top();
                v.push_back({top, i});
                opening.pop();
            }
        }

        int possibilities = pow(2, v.size());

        set<string> results;

        for (int i = 1; i < possibilities; i++) {
            vector<int> idx;
            for (int j = 0; j < v.size(); j++) {
                if (i & (int)pow(2, j) ) {
                    idx.push_back(v[j].first);
                    idx.push_back(v[j].second);
                }
            }
            sort(idx.begin(), idx.end());

            string res = "";

            int ind = 0;
            for (int j = 0; j < input.length(); j++) {
                if (ind < idx.size() && idx[ind] == j) {
                    ind++;
                } else {
                    res += input[j];
                }
            }

            results.insert(res);
        }

        for (auto i : results) {
            cout << i << endl;
        }
    }

    return 0;
}