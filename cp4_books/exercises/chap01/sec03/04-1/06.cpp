#include<bits/stdc++.h>

using namespace std;

int main () {
  int n, v, b, r = 0;
  cin >> n >> v;
  vector<int> L(n);
  b = __builtin_clz(n) >> 1;
  for (auto & e : L) cin >> e;
  for (r = 0; b > 0; b >>= 1)
    if ((r | b) < n && L[r | b] <= v) r |= b;
  cout << ((L[r] == v) ? "Yes" : "No") << '\n';
}
