#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    long long sum = 0;
    int temp;
    while (n--) {
        scanf("%d", &temp);
        if (temp < 0) sum -= temp;
    }
    printf("%d\n", sum);

}