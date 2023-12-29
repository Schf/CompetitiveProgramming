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

  ll s, b;
  cin >> s >>  b;

  vll A(s);
  trav (e, A)
	  cin >> e;

  vector<pll> B(b);
  trav(p, B)
	  cin >> p.f >> p.s;
  sort(B.begin(), B.end());
  for (i = 1; i < B.size(); ++i)
	  B[i].s += B[i - 1].s;

  for (i = 0; i < s; ++i){
	  for (j = 1<<30, n = 0; j > 0; j >>= 1)
		  if ((n | j) < b && B[n | j].f <= A[i])
			  n |= j;
	  if (B[n].f <= A[i])
		  A[i] = B[n].s;
	  else A[i] = 0;
  }

  trav(e, A) cout << e << ' ';
  cout << '\n';

  return 0;
}
