#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {


    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        int P, K, L;
        cin >> P >> K >> L;

        vector<int> numbers;
        priority_queue<int, vector<int>, greater<int>> pq(K, 1);

        for (int j = 0; j < L; j++) {
            int num;
            cin >> num;
            numbers.push_back(num);
        }

        sort(begin(numbers), end(numbers), greater<int>());

        ll result = accumulate(begin(numbers), end(numbers), 0ull, [&pq](ll current, ll next) {
            int top = pq.top();
            pq.pop();
            pq.push(top + 1);

            return current + top * next;
        });

        cout << "Case #" << i + 1 << ": " << result << endl;
    }

}