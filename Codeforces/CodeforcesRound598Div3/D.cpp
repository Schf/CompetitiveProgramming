#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector <ll> zpos;
		for (i = 0; i < n; ++i)
			if (s[i] == '0')
				zpos.push_back (i);
		for (i = 0; i < zpos.size () && zpos[i] - i <= k; ++i)
			k -= zpos[i] - i, zpos[i] = i;
		if (i < zpos.size ()) zpos[i] = max (zpos[i] - k, i);
		for (i = j = 0; i < n; ++i)
			if (j < zpos.size () && zpos[j] == i) cout << 0, ++j;
			else cout << 1;
		cout << '\n';
	}

	return 0;
}

