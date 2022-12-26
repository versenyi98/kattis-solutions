#include <bits/stdc++.h>

using namespace std;

struct flight {
	int from, to, day, size;
};

struct day {
	int airport, day, size;
};

int main() {

	int number_of_airports;
	int number_of_days;
	int number_of_flights;

	cin >> number_of_airports >> number_of_days >> number_of_flights;

	flight flights[number_of_flights];
	day days[number_of_airports * number_of_days];

	int people_in_city[number_of_days][number_of_airports];

	for (int i = 0; i < number_of_days; i++) {
		for (int j = 0; j < number_of_airports; j++) {
			people_in_city[i][j] = 0;
		}
	}

	for (int i = 0; i < number_of_flights; i++) {
		cin >> flights[i].from >> flights[i].to >> flights[i].day >> flights[i].size;
	}

	for (int i = 0; i < number_of_airports * number_of_days; i++) {
		cin >> days[i].airport >> days[i].day >> days[i].size;

		people_in_city[days[i].day - 1][days[i].airport - 1] += days[i].size;
	}

	bool wrong = false;

	for (int d = 1; !wrong && d <= number_of_days; d++) {
		for (int f = 0; !wrong && f < number_of_flights; f++) {
			if (flights[f].day == d) {
				if (people_in_city[d - 1][flights[f].from - 1] < flights[f].size) {
					wrong = true;
					break;
				} else {
					people_in_city[d - 1][flights[f].from - 1] -= flights[f].size;
					people_in_city[d % number_of_days][flights[f].to - 1] += flights[f].size;
				}
			}
		}
		if (wrong) break;
		for (int i = 0; i < number_of_airports; i++) {
			people_in_city[d % number_of_days][i] += people_in_city[d - 1][i];
		}
	}

	if (wrong) {
		cout << "suboptimal" << endl;
	} else {
		cout << "optimal" << endl;
	}

	return 0;
}