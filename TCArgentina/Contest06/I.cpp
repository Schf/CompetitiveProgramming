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
	ll tc = 1;
	cin >> tc;
	vector <ll> det (7, 6);
	for (ll i = 1; i < det.size (); ++i)
		det[i] = 6 - i,
		det[i] += det[i - 1];
	trav (a, det) cout << a << ' ';
	cout << '\n';
	for (ll cc = 1; cc <= tc; ++cc)
	{
		ll i, j, n;
		cin >> n;
		cout << (21*((n-7)/7)*((n-7)/7 + 1)/2 + (n/7)*det[n%7])%MOD << '\n';

	}

	vector <vector <ll>> pasc (42, vector <ll> (42, 1));
	for (ll i = 2; i < pasc.size (); ++i)
		for (ll j = 1; j < i; ++j)
			pasc[i][j] = (pasc[i - 1][j] + pasc[i - 1][j - 1]);
	for (ll i = 0; i < pasc.size (); ++i)
	{
		ll cnt = 0;
		trav (a, pasc[i])
			if (!(a%7)) ++cnt;
		if (i%7 == 0) cout << i << ": ";
		cout << cnt << ' ';
		if (i%7 == 6) cout << '\n';
	}

	return 0;
}

