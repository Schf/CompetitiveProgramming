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
	ll i, j, n, q;
	cin >> n >> q;
	if (n == 1)
	{
		ll c;
		cin >> c;
		for (i = 0; i < q; ++i)
		{
			ll t;
			cin >> t;
			if (t == 1)
			{
				ll x;
				cin >> x >> c;
			}
			else
			{
				ll tc;
				cin >> tc;
				if (tc == c) cout << 1 << '\n';
				else cout << 0 << '\n';
			}
		}
		return 0;
	}
	vector <ll> inp (n), freq (n + 1, 0);
	trav (a, inp) cin >> a;
	++freq[inp[0]];
	for (i = 1; i < n; ++i)
		if (inp[i] != inp[i - 1]) ++freq[inp[i]];
	for (i = 0; i < q; ++i)
	{
		ll t;
		cin >> t;
		if (t == 1)
		{
			ll x, c;
			cin >> x >> c;
			--x;
			if (c == inp[x]) continue;
			if (x == 0)
			{
				if (inp[0] != inp[1])
					--freq[inp[0]];
				if (c != inp[1])
					++freq[c];
			}
			else if (x == n - 1)
			{
				if (inp[n - 1] != inp[n - 2])
					--freq[inp[n - 1]];
				if (c != inp[n - 2])
					++freq[c];
			}
			else
			{
				if (inp[x - 1] == inp[x + 1])
				{
					if (inp[x] == inp[x - 1])
						++freq[inp[x]], ++freq[c];
					else if (c == inp[x - 1])
						--freq[inp[x]], --freq[c];
					else
						--freq[inp[x]], ++freq[c];
				}
				else
				{
					if (inp[x] != inp[x - 1] && inp[x] != inp[x + 1])
						--freq[inp[x]];
					if (c != inp[x - 1] && c != inp[x + 1])
					 	++freq[c];
				}
			}
			inp[x] = c;
		}
		else
		{
			ll c;
			cin >> c;
			cout << freq[c] << '\n';
		}
	}

	return 0;
}


