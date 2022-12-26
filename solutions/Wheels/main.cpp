#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(max(a, b) % min(a, b), min(a, b));
}

int sq(int a) {
	return a * (long long)a;
}

int main() {

	int n;
	scanf("%d", &n);

	while(n--) {
		int m;
		int x[1000], y[1000], r[1000];
		int movement[1000];

		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &x[i], &y[i], &r[i]);
			movement[i] = 0;
		}
		queue<int> moves;

		moves.push(0);
		movement[0] = 1;

		while (!moves.empty()) {

			int top = moves.front();
			moves.pop();

			for (int i = 0; i < m; i++) {
				//cout << top << " " << i << " " << sq(r[top] + r[i]) << " " << sq(x[top] - x[i]) << " " << sq(y[top] - y[i]) << " " << movement[i] << endl;
				if (movement[i] == 0 && sq(x[i] - x[top]) + sq(y[i] - y[top]) == sq(r[top] + r[i])) {
					movement[i] = -movement[top];
					moves.push(i);
				}
			}
		}

		for (int i = 0; i < m; i++) {
			if (movement[i] == 0) {
				printf("not moving\n");
			} else {
				int div = gcd(r[0], r[i]);
				printf("%d", r[0]/div);
				if (r[i] > div) {
					printf("/%d", r[i]/div);
				}

				if (movement[i] == 1) {
					printf(" clockwise\n");
				} else {
					printf(" counterclockwise\n");
				}
			}
		}

	}

}