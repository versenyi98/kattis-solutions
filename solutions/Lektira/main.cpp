#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    while (cin >> s) {
        string mini = s;
        for (int i = 1; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                string s1 = s.substr(0, i);
                string s2 = s.substr(i, j - i);
                string s3 = s.substr(j);

                reverse(s1.begin(), s1.end());
                reverse(s2.begin(), s2.end());
                reverse(s3.begin(), s3.end());
                string ss = s1 + s2 + s3;
                mini = min(mini, ss);
            }
        }
        cout << mini << endl;

    }

    return 0;
}