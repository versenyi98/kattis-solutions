#include <bits/stdc++.h>

using namespace std;

class UFDS {
	public:
		UFDS(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) parent[i] = i;
		}

		int get_parent(int n) {
			if (parent[n] == n) return n;
			return parent[n] = get_parent(parent[n]);
		}

		bool is_same_set(int n, int m) {
			return get_parent(n) == get_parent(m);
		}

		void join(int n, int m) {
			parent[get_parent(n)] = get_parent(m);
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

	for (int tt = 0; tt < test_cases; tt++) {
		int n;
		cin >> n;

		vector<pair<double, double>> v(n);
		vector<pair<double, pair<int, int>>> edges;

		UFDS ufds(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i].first >> v[i].second;
			for (int j = 0; j < i; j++) {
				edges.push_back({sqrt(pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2)), {i, j}});
			}
		}

		sort(edges.begin(), edges.end(), [](auto a, auto b) {
			return a.first < b.first;
		});

		double total_cost = 0;
		for (auto i : edges) {
			if (!ufds.is_same_set(i.second.first, i.second.second)) {
				ufds.join(i.second.first, i.second.second);
				total_cost += i.first;
			}
		}
		printf("%.8f\n", total_cost);
	}

	return 0;
}