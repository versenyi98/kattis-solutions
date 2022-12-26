#include <bits/stdc++.h>

using namespace std;

class UFDS {

	public:
		UFDS(int n) {
			for (int i = 0; i < n + 1; i++) {
				parent.push_back(i);
				size.push_back(1);
			}
		}

		int get_set(int n) {
			if (parent[n] == n) return n;

			int res = get_set(parent[n]);
			parent[n] = res;

			return res;
		}

		bool is_same_set(int n, int m) {
			return get_set(n) == get_set(m);
		}

		void join(int n, int m) {
			int np = get_set(n);
			int mp = get_set(m);
			if (np == mp) return;

			int ns = get_size(n);
			int ms = get_size(m);

			size[mp] = 0;
			size[np] += ms;

			parent[mp] = np;
		}

		int get_size(int n) {
			return size[get_set(n)];
		}

		void decr_size(int n) {
			size[get_set(n)]--;
		}

	private:
		vector<int> parent;
		vector<int> size;
};

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	UFDS ufds(m);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		ufds.join(a, b);

		if (ufds.get_size(a) == 0) {
			printf("SMECE\n");
		} else {
			ufds.decr_size(a);
			printf("LADICA\n");
		}
	}

	return 0;
}