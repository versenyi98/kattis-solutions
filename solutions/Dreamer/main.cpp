#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

bool is_leap(int n) {
    if (n % 400 == 0) return true;
    if (n % 100 == 0) return false;
    return n % 4 == 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<int, int> m;
    m[1] = m[3] = m[5] = m[7] = m[8] = m[10] = m[12] = 31;
    m[4] = m[6] = m[9] = m[11] = 30;
    m[2] = 28;

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        map<string, bool> used;
        string date, s1, s2, s3;

        cin >> s1 >> s2 >> s3;
        date = s1 + s2 + s3;

        string m_date = "99999999";
        int cc = 0;

        sort(date.begin(), date.end());
        do {
            int year = stoi(date.substr(0, 4));
            int month = stoi(date.substr(4, 2));
            int day = stoi(date.substr(6, 2));

            if (year >= 2000) {
                if (month > 0 && month <= 12) {
                    if ((day > 0 && day <= m[month]) || (day == 29 && month == 2 && is_leap(year))) {
                        if (!used[date]) {
                            used[date] = true;
                            cc++;
                            m_date = min(m_date, date);
                        }
                    }
                }
            }
        } while (next_permutation(date.begin(), date.end()));

        if (cc == 0) {
            cout << cc << endl;
            continue;
        }
        cout << cc << " " << m_date.substr(6, 2) << " " << m_date.substr(4, 2) << " " << m_date.substr(0, 4) << endl;
    }

    return 0;
}