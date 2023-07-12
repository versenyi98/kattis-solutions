#include <bits/stdc++.h>

using namespace std;

int main() {

    string common_word;
    cin >> common_word;

    int endings;
    cin >> endings;

    vector<pair<vector<string>, bool>> rhymes(endings);

    string line;
    getline(cin, line);

    while (endings--) {
        rhymes[endings].second = false;

        getline(cin, line);

        for (size_t pos = line.find(' ');; pos = line.find(' ')) {
            auto word = line.substr(0, pos);

            if (auto cpos = common_word.rfind(word); cpos != string::npos && cpos + word.length() == common_word.length()) {
                rhymes[endings].second = true;
            }

            rhymes[endings].first.push_back(word);
            if (pos == string::npos) {
                break;
            }
            line = line.substr(pos + 1);
        }
    }

    int lines;
    cin >> lines;
    getline(cin, line);

    while (lines--) {
        getline(cin, line);

        if (any_of(begin(rhymes), end(rhymes), [&line](auto v) {
            return v.second && any_of(begin(v.first), end(v.first), [&line](auto w) {
                auto pos = line.rfind(w);
                return pos != string::npos && pos + w.length() == line.length();
            });
        })) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

}