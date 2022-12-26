#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

long long sieve_size;
bitset<40000> bs;
vector<long long> p;

void sieve(long long upper) {

    sieve_size = upper;

    bs.set();

    bs[0] = bs[1] = 0;

    for (long long i = 2; i < sieve_size; i++) {
        if (bs[i]) {
            for (long long j = i * i; j < sieve_size; j += i) {
                bs[j] = 0;
            }
            p.push_back(i);
        }
    }
}

bool isPrime(long long n) {
    if (n < sieve_size) return bs[n];

    for (int i = 0; i < p.size() && p[i] * p[i] <= n; i++) {
        if (n % p[i] == 0) return false;
    }
    return true;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve(40000);

    long long a;
    while (cin >> a, a) {
        long long b = a * 2 + 1;

        while (!isPrime(b)) {
            b++;
        }

        cout << b;
        if (!isPrime(a)) {
            cout << " (" << a << " is not prime)";
        }
        cout << endl;
    }

    return 0;
}