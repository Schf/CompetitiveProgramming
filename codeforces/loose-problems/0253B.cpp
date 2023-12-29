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
  int i, j, n;

  FILE *in = fopen("input.txt", "r");
  FILE *out = fopen("output.txt", "w");
  fscanf(in, "%d", &n);

  vector<int> c(n);
  trav(a, c) fscanf(in, "%d", &a);
  sort(c.begin(), c.end());

  int ans = n + 7;
  for (i = 0; i < c.size(); ++i) {
    int doub;

    for (j = 1 << 30, doub = i; j > 0; j >>= 1)
      if (0 <= doub + j && doub + j < c.size() && c[doub + j] <= c[i] * 2)
        doub += j;

    ans = min(ans, n - doub - 1 + i);
  }

  fprintf(out, "%d\n", ans);
  fclose(in);
  fclose(out);

  return 0;
}
