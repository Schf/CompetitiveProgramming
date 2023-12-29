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
  ll i, j, n, loops = INFLL;
  cin >> n;

  vll a(n);
  for (i = 0; i < n; ++i)
    cin >> a[i], a[i] -= i, loops = min(loops, (a[i] + n - 1) / n);

  for (i = 0; i < n; ++i)
    if (a[i] - n * loops <= 0)
      break;

  cout << i + 1 << '\n';

  return 0;
}
