#include <bits/stdc++.h>

using namespace std;

class UFDS {
	public:
		UFDS(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) parent[i] = i;
		}

		int get_parent(int n) {
			if (n == parent[n]) return n;
			return parent[n] = get_parent(parent[n]);
		}

		void join(int n, int m) {
			parent[get_parent(n)] = get_parent(m);
		}

		int is_same_set(int n, int m) {
			return get_parent(n) == get_parent(m);
		}

	private:
		vector<int> parent;
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int test_cases;
	cin >> test_cases;

	for (int i = 0; i < test_cases; i++) {
		int n, m;
		cin >> n >> m;

		UFDS ufds(n);
		vector<pair<int, pair<int, int>>> edges(m * (m - 1) / 2);

		for (int j = 0; j < m * (m - 1) / 2; j++) {
			int a, b, c;
			cin >> edges[j].second.first >> edges[j].second.second >> edges[j].first;
		}

		sort(edges.begin(), edges.end(), [] (auto a, auto b) {
			return a.first < b.first;
		});

		int spilled = 0;
		for (auto j : edges) {
			if (!ufds.is_same_set(j.second.first, j.second.second)) {
				ufds.join(j.second.second, j.second.first);
				spilled += j.first;
			}
		}


		if (spilled + m <= n) {
			cout << "yes" << endl;
		} else {
			cout << "no" << endl;
		}
	}

	return 0;
}