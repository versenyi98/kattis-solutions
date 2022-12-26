#include <bits/stdc++.h>

using namespace std;

class UFDS {
	public:
		UFDS(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) parent[i] = i;
		}

		int find(int n) {
			if (n == parent[n]) return n;
			return parent[n] = find(parent[n]);
		}

		bool is_same_set(int n, int m) {
			return find(n) == find(m);
		}

		void join(int n, int m) {
			parent[find(n)] = find(m);
		}

	private:
		vector<int> parent;
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	UFDS ufds(n);

	vector<pair<int, pair<int, int>>> edges;
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (i >= j) continue;
			edges.push_back({temp, {i, j}});
		}
	}

	sort(edges.begin(), edges.end(), [](auto a, auto b) {
		return a.first < b.first;
	});

	for (auto i : edges) {
		if (!ufds.is_same_set(i.second.first, i.second.second)) {
			cout << i.second.first + 1 << ' ' << i.second.second + 1 << endl;
			ufds.join(i.second.first, i.second.second);
		}
	}

	return 0;
}