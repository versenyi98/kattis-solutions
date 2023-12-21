#include <iostream>
#include <vector>
#include <math.h>
#include <climits>

using namespace std;

 int main() {

  long long kindOfTea;
  cin >> kindOfTea;

  vector<long long> priceOfTea;

  for (long long i = 0; i < kindOfTea; i++) {
    long long temp;
    cin >> temp;
    priceOfTea.push_back(temp);
  }

  long long kindOfTopping;
  cin >> kindOfTopping;

  vector<long long> priceOfTopping;
  for (long long i = 0; i < kindOfTopping; i++) {
    long long temp;
    cin >> temp;

    priceOfTopping.push_back(temp);
  }

  long long minPrice = LLONG_MAX;
  for (long long i = 0; i < kindOfTea; i++) {
    long long pieces;
    cin >> pieces;

    for (long long j = 0; j < pieces; j++) {
      long long temp;
      cin >> temp;
      minPrice = min(minPrice, priceOfTea[i] + priceOfTopping [temp - 1]);
    }
  }
  long long money;
  cin >> money;

  cout << max((long long)0, money/minPrice - 1) << endl;
}
