#include <bits/stdc++.h>

using namespace std;

class UFDS {
	public:
		UFDS(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) parent[i] = i;
		}

		int find(int n) {
			return n == parent[n] ? n : parent[n] = find(parent[n]);
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

	int n, m;
	cin >> n >> m;

	int arr[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	vector<pair<int, pair<int, int>>> edges[n * m];

	int x[] = {-1, +1, 0, 0};
	int y[] = {0, 0, -1, +1};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				int ik = i + x[k];
				int jk = j + y[k];
				if (ik < 0 || ik == n || jk < 0 || jk == m) continue;
				edges[i * m + j].push_back({max(0, arr[ik][jk] - arr[i][j]), {i * m + j, ik * m + jk}});
			}
		}
	}

	int ladder = 0;
	auto comp = [] (pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
		return a.first > b.first;
	};

	UFDS ufds(n * m);
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> pq(comp);
	for (auto i : edges[0]) pq.push(i);

	bool in_pq[n * m] = {false};
	in_pq[0] = true;

	while (pq.size()) {
		auto front = pq.top();
		pq.pop();

		if (!ufds.is_same_set(front.second.first, front.second.second)) {
			ufds.join(front.second.first, front.second.second);
			ladder = max(ladder, front.first);

			if (in_pq[front.second.first]) {
				for (auto j : edges[front.second.second]) pq.push(j);
			} else {
				for (auto j : edges[front.second.first]) pq.push(j);
			}

			in_pq[front.second.second] = true;
			in_pq[front.second.first] = true;

			if (max(front.second.first, front.second.second) == n * m - 1) {
				break;
			}
		}
	}

	cout << ladder << endl;

	return 0;
}