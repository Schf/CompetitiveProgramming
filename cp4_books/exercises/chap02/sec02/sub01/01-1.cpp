#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<tuple<int, string, string>> v (n);
  for (auto &e : v)
    cin >> get<0>(e) >> get<2>(e) >> get<1>(e);

  sort(v.begin(), v.end(), [&](auto &a, auto &b) {
    if (get<0>(a) != get<0>(b))
      return get<0>(a) < get<0>(b);
    if (get<1>(a) != get<1>(b))
      return get<1>(a) > get<1>(b);
    return get<2>(a) < get<2>(b);
  });

  for (auto &e : v)
    cout << get<0>(e) << ' ' << get<2>(e) << ' ' << get<1>(e) << '\n';
}
