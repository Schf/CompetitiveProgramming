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
	ll i, j, n, m;
	string s;
	cin >> n >> s;
	s += (char) ('z' + 1);
	for (i = 0; i < n; ++i)
		s += s[n - i - 1];
	n = s.size ();
	vector <ll> suf (n), rnk (2*n, -1), prv (2*n, -1);
	for (i = 0; i < n; ++i) suf[i] = i, prv[i] = s[i];
	for (i = 1; i < n; i *= 2)
	{
		sort (suf.begin (), suf.end (), [&] (ll it, ll jt) {
			if (prv[it] == prv[jt])
				return prv[it + i] < prv[jt + i];
			return prv[it] < prv[jt];
		});
		rnk[suf[0]] = 0;
		for (j = 1; j < n; ++j)
			rnk[suf[j]] = rnk[suf[j - 1]] + (prv[suf[j]] != prv[suf[j - 1]] ||
					prv[suf[j] + i] != prv[suf[j - 1] + i]);
		copy (rnk.begin (), rnk.end (), prv.begin ());
	}
	vector <ll> lcp (n, 0);
	ll cur = 0;
	if (rnk[cur] == n - 1) ++cur;
	for (i = 0; i < n - max (cur, suf[rnk[cur] + 1]); ++i)
		if (s[cur + i] == s[suf[rnk[cur] + 1] + i])
			++lcp[rnk[cur]];
		else break;
	for (++cur; cur < n; ++cur)
	{
		if (rnk[cur] == n - 1) continue;
		i = max (lcp[rnk[cur - 1]] - 1, 0LL);
		lcp[rnk[cur]] = i;
		for (; i < n - max (cur, suf[rnk[cur] + 1]); ++i)
			if (s[cur + i] == s[suf[rnk[cur] + 1] + i])
				++lcp[rnk[cur]];
			else break;
	}
	ll ans = 0;
	for (i = 0; i < n - 1; ++i)
		if (min (suf[i], suf[i + 1]) < s.size ()/2 &&
				max (suf[i], suf[i + 1]) > s.size ()/2)
			ans = max (ans, lcp[i]);
	cout << ans << '\n';

	return 0;
}

