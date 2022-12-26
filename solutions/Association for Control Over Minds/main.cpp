#include <bits/stdc++.h>

using namespace std;

class UFDS {

	public:
		UFDS(int size) {
			this->parent.reserve(size);
			this->size.reserve(size);

			for (int i = 0; i < size; i++) {
				this->parent[i] = i;
				this->size[i] = 1;
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
			int n_parent = get_set(n);
			int m_parent = get_set(m);
			if (n_parent == m_parent) return;

			int n_size = get_size(n_parent);

			size[m_parent] += n_size;
			size[n_parent] = 0;

			parent[n_parent] = m_parent;
		}

		int get_size(int n) {
			return size[get_set(n)];
		}

	private:
		vector<int> parent;
		vector<int> size;
};

int main() {

	int n;
	scanf("%d", &n);

	UFDS ufds(500001);
	int counter = 0;
	for (int i = 0; i < n; i++) {
		int nn;
		scanf("%d", &nn);

		int arr[nn];
		map<int, int> occur;

		for (int j = 0; j < nn; j++) {
			scanf("%d", &arr[j]);

			occur[ufds.get_set(arr[j])]++;
		}

		bool good = true;
		for (auto j : occur) {
			if (ufds.get_size(j.first) != j.second) good = false;
		}

		if (good) {
			counter++;
			for (int j = 1; j < nn; j++) {
				ufds.join(arr[0], arr[j]);
			}
		}
	}

	printf("%d\n", counter);

	return 0;
}