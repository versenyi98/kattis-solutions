#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int it;
    cin >> it;
    uint64_t start = 2;
    
    for (int i = 0; i < it; i++) {
        start += start - 1;
    }
    uint64_t res = start * start;
    cout << res << endl;
   
}