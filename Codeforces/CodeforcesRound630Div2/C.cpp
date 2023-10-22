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
		ll i, j, n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector <set <ll>> poss (k);
		for (i = 0; i < k; ++i)
			for (j = i; j < s.size (); j += k)
				poss[i].insert (j), poss[i].insert (s.size () - j - 1);
		set <set <ll>> gamb;
		trav (s, poss) gamb.insert (s);
		vector <vector <ll>> groups;
		trav (s, gamb)
		{
			groups.emplace_back ();
			trav (a, s)
				groups[groups.size () - 1].push_back (a);
		}
		vector <vector <ll>> freq (groups.size (), vector <ll> ('z' + 1, 0));
		vector <ll> point (s.size ());
		for (i = 0; i < groups.size (); ++i)
			for (j = 0; j < groups[i].size (); ++j)
				++freq[i][s[groups[i][j]]], point[groups[i][j]] = i;
		vector <ll> mxs (groups.size ());
		for (i = 0; i < groups.size (); ++i)
			for (mxs[i] = 'a', j = 'b'; j <= 'z'; ++j)
				if (freq[i][mxs[i]] < freq[i][j])
					mxs[i] = j;
		ll ans = 0;
		for (i = 0; i < s.size (); ++i)
			if (s[i] != mxs[point[i]]) ++ans;
		cout << ans << '\n';
	}

	return 0;
}


