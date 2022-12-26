#include <bits/stdc++.h>

using namespace std;

class UFDS {
	public:
		UFDS(int64_t n) {
			parent.resize(n);
			for (int64_t i = 0; i < n; i++) parent[i] = i;
		}

		int64_t get_parent(int64_t n) {
			return (parent[n] == n ? n : parent[n] = get_parent(parent[n]));
		}

		void join(int64_t n, int64_t m) {
			parent[get_parent(n)] = get_parent(m);
		}

		bool is_same_set(int64_t n, int64_t m) {
			return get_parent(n) == get_parent(m);
		}

	private:
		vector<int64_t> parent;
};


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int64_t n, m;
	while (cin >> n >> m, n || m) {
		UFDS ufds(n);
		vector<pair<int64_t, int64_t>> result;
		vector<pair<int64_t, pair<int64_t, int64_t>>> edges(m);

		for (int64_t i = 0; i < m; i++) {
			cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
			int64_t minimum = min(edges[i].second.first, edges[i].second.second);
			edges[i].second.second = max(edges[i].second.first, edges[i].second.second);
			edges[i].second.first = minimum;
		}

		sort(edges.begin(), edges.end());
		int64_t cost = 0;

		for (auto i : edges) {
			if (!ufds.is_same_set(i.second.second, i.second.first)) {
				ufds.join(i.second.second, i.second.first);
				result.push_back(i.second);
				cost += i.first;
			}
		}

		sort(result.begin(), result.end());

		if (result.size() == n - 1) {
			cout << cost << endl;
			for (auto i : result) {
				cout << i.first << ' ' << i.second << endl;
			}
		} else {
			cout << "Impossible" << endl;
		}
	}

	return 0;
}