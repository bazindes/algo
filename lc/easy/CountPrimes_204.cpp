/*
  CountPrimes_204.cpp
  Created by: baz
  Date: 2019-04-02 20:40
*/
#include <cmath>
#include <vector>
using namespace std;

int countPrimes(int n) {
  vector<int> seive(n + 1, 1);

  for (int i = 2; i <= sqrt(n); i++) {
    if (seive[i] == 1) {
      for (int j = i * i; j <= n; j = j + i) {
        seive[j] = 0;
      }
    }
  }
  int cnt = 0;
  for (int i = 2; i < n; i++)
    if (seive[i])
      cnt++;
  return cnt;
}
