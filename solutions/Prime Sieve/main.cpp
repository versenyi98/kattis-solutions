#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

long long sieve_size;
bitset<100000010> bs;
vector<long long> primes;

long long sieve(long long n) {
    long long ret = 0;
    sieve_size = n;
    bs.set();

    bs[0] = bs[1] = 0;

    for (long long i = 2; i <= sieve_size; i++) {
        if (bs[i]) {
            for (long long j = i * i; j <= sieve_size; j += i) {
                bs[j] = 0;
            }
            ret++;
        }
    }

    return ret;
}

bool isPrime(long long n) {
    return bs[n];
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n, q;
    cin >> n >> q;

    cout << sieve(n) << endl;

    for (int i = 0; i < q; i++) {
        long long a;
        cin >> a;

        cout << isPrime(a) << endl;
    }

    return 0;
}