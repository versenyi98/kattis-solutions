#include <bits/stdc++.h>

using namespace std;

set<string> s;

void alakit(string &str) {

    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i]) && isupper(str[i])) {
            str[i] = tolower(str[i]);
        } else if (str[i] == '-') {
            str[i] = ' ';
        }
    }
}

int main() {

    int  n;
    cin >> n;

    string str;
    getline(cin, str);
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        alakit(str);
        s.insert(str);
    }

    cout << s.size() << endl;

}