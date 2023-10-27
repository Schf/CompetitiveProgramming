#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  for (int AA = 0; AA < 30; ++AA) {
    ll a = 1;
    for (ll i = 1; i <= AA; ++i)
      a = ((a * i) / (999 * ((a * i) % 1000 == 0) + 1)) % 1000;
    while (a && (a % 10 == 0))
      a /= 10;
    cout << a % 10 << '\n';
  }

  return 0;
}
