#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, A) for (auto & a : A)
#define all(a) (a).begin (), (a).end ()
#define f first
#define s second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

#define dd(...) #__VA_ARGS__ << ": " << __VA_ARGS__ << ", "

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, m, k, i, j;
		cin >> n >> m >> k;
		vector <int> A (n);
		trav (a, A) cin >> a;
		k = min (--m, k); m -= k;
		int ans = 0;
		for (i = 0; i <= k; ++i)
		{
			int temp_ans = INF;
			for (j = 0; j <= m; ++j)
			{
				int L = A[i + j];
				int R = A[n - k + i - 1 - m + j];
				temp_ans = min (temp_ans, max (L, R));
			}
			ans = max (ans, temp_ans);
		}
		cout << ans << '\n';
	}

	return 0;
}


