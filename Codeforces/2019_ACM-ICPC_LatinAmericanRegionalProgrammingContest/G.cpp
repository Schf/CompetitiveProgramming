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

void make_suff (vector <ll> & suf, string & s)
{
	ll n = s.size (), i, j;
	vector <ll> prv (2*n, -1), rnk (2*n, -1);
	for (i = 0; i < n; ++i)
		suf[i] = i;
	sort (suf.begin (), suf.end (), [&] (ll it, ll jt) {return s[it] < s[jt];});
	prv[suf[0]] = 0;
	for (j = 1; j < n; ++j)
		prv[suf[j]] = prv[suf[j - 1]] + (s[suf[j]] != s[suf[j - 1]]);
	for (i = 1; i < n; i *= 2)
	{
		sort (suf.begin (), suf.end (), [&] (ll it, ll jt) {
			if (prv[it] == prv[jt]) return prv[it + i] < prv[jt + i];
			return prv[it] < prv[jt];
		});
		rnk[suf[0]] = 0;
		for (j = 1; j < n; ++j)
			rnk[suf[j]] = rnk[suf[j - 1]] +
					(prv[suf[j]] != prv[suf[j - 1]] ||
					prv[suf[j] + i] != prv[suf[j - 1] + i]);
		copy (rnk.begin (), rnk.end (), prv.begin ());
	}
}

bool find (vector <ll> & suff, string & s, string & cur, ll & bgn)
{
	if (suff.size () == 1)
		if (cur[bgn] == s[suff[0]]) { ++bgn; return true; }
		else return false;
	ll i, j, u = suff.size () - 1, l = 0;
	for (i = 0; i + bgn < cur.size () && l < u; ++i)
	{
		ll ub = u, lb = l, mb = (ub + lb + 1) / 2;
		while (ub - lb > 1)
		{
			if (s[suff[mb] + i] < cur[bgn + i]) lb = mb;
			else ub = mb;
			mb = (ub + lb + 1) / 2;
		}
		if (s[suff[mb - 1] + i] == cur[bgn + i]) --mb;
		if (s[suff[mb] + i] != cur[bgn + i])
			if (i == 0) return false;
			else { bgn += i; return true; }
		l = mb;
		if (l >= u) break;

		ub = u, lb = l, mb = (ub + lb) / 2;
		while (ub - lb > 1)
		{
			if (s[suff[mb] + i] <= cur[bgn + i]) lb = mb;
			else ub = mb;
			mb = (ub + lb) / 2;
		}
		if (s[suff[mb + 1] + i] == cur[bgn + i]) ++mb;
		if (s[suff[mb] + i] != cur[bgn + i])
			if (i == 0) return false;
			else { bgn += i; return true; }
		u = mb;

		while (suff[l] + i + 1 >= s.size () && l < u) ++l;
	}
	while (l > u) --l;
	while (i + bgn < cur.size () && suff[u] + i < s.size () &&
			s[suff[u] + i] == cur[bgn + i])
		++i;
	bgn += i;
	return true;
}

ll count (vector <ll> & suff, string & s, string & cur)
{
	ll ans = 0, i, j;
	for (i = 0; i < cur.size ();)
		if (!find (suff, s, cur, i)) return -1;
		else ++ans;
	return ans;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	string s, cur;
	cin >> s >> n;
	vector <ll> suff (s.size ());
	make_suff (suff, s);
	for (i = 0; i < n; ++i)
		cin >> cur, cout << count (suff, s, cur) << '\n';

	return 0;
}

