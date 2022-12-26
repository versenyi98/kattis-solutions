#include <bits/stdc++.h>

using namespace std;

class UFDS {

	public:
		UFDS(uint64_t n) {
			parent.resize(2 * n);
			sum.resize(2 * n);
			size.resize(2 * n);

			for (uint64_t i = 0; i < 2 * n; i++) {
				parent[i] = i % n + n;
				sum[i] = i % n;
				size[i] = 1;
			}
		}

		uint64_t get_parent(uint64_t n) {
			if (n == parent[n]) return n;
			uint64_t res = get_parent(parent[n]);
			parent[n] = res;
			return res;
		}

		void move(uint64_t n, uint64_t m) {
			uint64_t np = get_parent(n);
			uint64_t mp = get_parent(m);
			if (mp == np) return;

			sum[np] -= n;
			sum[mp] += n;

			size[np]--;
			size[mp]++;

			parent[n] = mp;
		}

		void join(uint64_t n, uint64_t m) {
			uint64_t np = get_parent(n);
			uint64_t mp = get_parent(m);
			if (np == mp) return;

			sum[mp] += sum[np];
			sum[np] = 0;
			size[mp] += size[np];
			size[np] = 0;
			parent[np] = mp;
		}

	vector<uint64_t> parent;
	vector<uint64_t> sum;
	vector<uint64_t> size;
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	uint64_t n, m;

	while (cin >> n >> m) {

		UFDS ufds(n + 1);

		for (uint64_t i = 0; i < m; i++) {
			uint64_t opt;
			cin >> opt;
			if (opt == 1) {
				uint64_t from, to;
				cin >> from >> to;
				ufds.join(from, to);
			} else if (opt == 2) {
				uint64_t from, to;
				cin >> from >> to;
				ufds.move(from, to);
			} else {
				uint64_t q;
				cin >> q;
				cout << ufds.size[ufds.get_parent(q)] << " " << ufds.sum[ufds.get_parent(q)] << endl;
			}
		}
	}
	return 0;
}