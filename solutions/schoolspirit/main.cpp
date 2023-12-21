#include <bits/stdc++.h>

using namespace std;

int scores[50];
int n;

double calc_score(int ignore = -1) {

    double res = 0;
    bool ignored = false;

    for (int i = 0; i < n; i++) {
        if (i == ignore) {
            ignored = true;
            continue;
        } 

        int j = ignored ? i - 1 : i; 
        res += scores[i] * pow(4.0/5.0, j);
    }

    return res / 5;
}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }

    printf("%.8f\n", calc_score());

    double res = 0;
    for (int i = 0; i < n; i++) {
        res += calc_score(i);
    }
    printf("%.8f\n", res/n);
}