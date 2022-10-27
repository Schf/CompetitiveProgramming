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

ll fat (ll n)
{
	if (n <= 1) return 1;
	else return (n * fat (n - 1)) % MOD;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, ans = 0;
	cin >> n >> MOD;
	vector <ll> fat (n + 1);
	fat[0] = fat[1] = 1;
	for (i = 2; i <= n; ++i)
		fat[i] = (i*fat[i - 1]) % MOD;
	for (i = 1; i <= n; ++i)
		ans = (ans + (((fat[i]*(n-i+1))%MOD)*fat[n-i+1])%MOD)%MOD;
	cout << ans << '\n';

	/*ll i, j, n, N = 9;
	//cin >> n >> MOD;
	vector <vector <ll>> seq (N);
	for (i = 1; i <= N; ++i)
	{
		cout << i << ": ";
		n = i;
		ll ans = 0;
		vector <ll> inp (n);
		vector <ll> freq (n, 0);
		iota (inp.begin (), inp.end (), 1);
		do
		{
			for (ll l = 0; l < n; ++l)
				for (ll r = l; r < n; ++r)
				{
					ll mn = INF, mx = 0;
					for (j = l; j <= r; ++j)
						mn = min (mn, inp[j]),
						mx = max (mx, inp[j]);
					if (mx - mn == r - l)
						++ans,
						++freq[r - l];
				}
		} while (next_permutation (inp.begin (), inp.end ()));
		cout << ans << endl;
		for (j = 0; j < freq.size (); ++j)
			cout << '\t' << j + 1 << ": " << freq[j] << endl,
			seq[j].push_back (freq[j]);
	}
	for (i = 0; i < seq.size (); ++i)
	{
		cout << i + 1 << ":";
		for (j = 0; j < seq[i].size (); ++j)
			cout << ' ' << seq[i][j]/seq[i][0];
		cout << endl;
	}*/

	return 0;
}

