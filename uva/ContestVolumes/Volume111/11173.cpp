#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto &a : A)
#define f first
#define s second

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

const ll MOD = 1e+9 + 7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5 + 7;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll i, j, n, k, acc, temp;

  int TC;
  cin >> TC;
  while (TC--) {
    cin >> n >> k;
    for (i = n - 1, j = acc = 0; i >= 0; --i)
      j = (j << 1) | ((k >> i) & 1) ^ (__builtin_popcount(j) & 1);
    cout << j << '\n';
  }

  return 0;
}
