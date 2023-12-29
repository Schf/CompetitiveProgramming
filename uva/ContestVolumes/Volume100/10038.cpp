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
  ll i, j, n;

  while (cin >> n) {
    if (n <= 0) {
      cout << "Not jolly\n";
      continue;
    }
    vll v(n), cc(n, 0);
    trav(e, v) cin >> e;
    for (int i = 1; i < n; ++i)
      if(abs(v[i] - v[i - 1]) < n)
        cc[min(n - 1, abs(v[i] - v[i - 1]))]++;
    bool jolly = true;
    for (int i = 1; i < n; ++i)
      jolly = jolly && cc[i];
    if (jolly)
      cout << "Jolly\n";
    else
      cout << "Not jolly\n";
  }

  return 0;
}
