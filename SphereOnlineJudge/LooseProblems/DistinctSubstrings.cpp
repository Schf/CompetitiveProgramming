#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n, m;
		string s;
		cin >> s;
		n = s.size ();
		vector <ll> suf (n);
		for (m = 0; (1<<m) < n; ++m);
		vector <vector <ll>> rnk (++m, vector <ll> (2*n, -1));
		for (i = 0; i < n; ++i) suf[i] = i;
		sort (suf.begin (), suf.end (), [&] (ll it, ll jt) {return s[it] < s[jt];});
		rnk[0][suf[0]] = 0;
		for (j = 1; j < n; ++j)
			rnk[0][suf[j]] = rnk[0][suf[j - 1]] + (s[suf[j]] != s[suf[j - 1]]);
		for (i = 0; (1<<i) < n; ++i)
		{
			sort (suf.begin (), suf.end (), [&] (ll it, ll jt) {
				if (rnk[i][it] == rnk[i][jt])
					return rnk[i][it + (1<<i)] < rnk[i][jt + (1<<i)];
				return rnk[i][it] < rnk[i][jt];
			});
			rnk[i + 1][suf[0]] = 0;
			for (j = 1; j < n; ++j)
				rnk[i + 1][suf[j]] = rnk[i + 1][suf[j - 1]] +
						(rnk[i][suf[j]] != rnk[i][suf[j - 1]] ||
						rnk[i][suf[j] + (1<<i)] != rnk[i][suf[j - 1] + (1<<i)]);
		}
		vector <ll> lcp (n, 0);
		ll cur = 0;
		if (rnk[m - 1][cur] == n - 1) ++cur;
		for (i = 0; i < n - max (cur, suf[rnk[m - 1][cur] + 1]); ++i)
			if (s[cur + i] == s[suf[rnk[m - 1][cur] + 1] + i])
				++lcp[rnk[m - 1][cur]];
			else break;
		for (++cur; cur < n; ++cur)
		{
			if (rnk[m - 1][cur] == n - 1) continue;
			i = max (lcp[rnk[m - 1][cur - 1]] - 1, 0LL);
			lcp[rnk[m - 1][cur]] = i;
			for (; i < n - max (cur, suf[rnk[m - 1][cur] + 1]); ++i)
				if (s[cur + i] == s[suf[rnk[m - 1][cur] + 1] + i])
					++lcp[rnk[m - 1][cur]];
				else break;
		}
		for (i = 0; i < n; ++i)
		{
			cout << lcp[i] << " | ";
			for (j = suf[i]; j < n; ++j) cout << s[j];
			cout << '\n';
		}
		ll ans = n*(n + 1)/2;
		trav (a, lcp) ans -= a;
		cout << ans << '\n';
	}

	return 0;
}

