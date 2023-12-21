#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, goal;
    cin >> n >> goal;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    vector<optional<char>> upside_down = {'0', '1', '2', {}, {}, '5', '9', {}, '8', '6'};

    auto flip = [&upside_down] (int number) {
        auto number_str = to_string(number);

        for (int i = 0; i < number_str.length(); i++) {
            int n = number_str[i] - '0';
            if (upside_down[n]) {
                number_str[i] = upside_down[n].value();
            } else {
                return optional<int>();
            }
        }

        reverse(number_str.begin(), number_str.end());
        return optional<int>(stoi(number_str));
    };

    vector<optional<int>> flipped;
    transform(numbers.begin(), numbers.end(), back_inserter(flipped), [flip](int number) {
        return flip(number);
    });

    map<int, set<int>> mapping;

    for (int i = 0; i < n; i++) {
        mapping[numbers[i]].insert(i);
        if (flipped[i]) {
            mapping[flipped[i].value()].insert(i);
        }
    }

    for (auto [key, values] : mapping) {
        if (auto it = mapping.find(goal - key); it != mapping.end()) {
            set<int> s = values;
            s.insert(it->second.begin(), it->second.end());

            if (s.size() != 1) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;

}