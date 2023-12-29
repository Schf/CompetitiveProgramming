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
		ll i, j, n;
		cin >> n;
		vector <ll> inp (n);
		trav (a, inp) cin >> a;
		sort (inp.begin (), inp.end ());
		bool can = true;
		for (i = 1; i < n; ++i)
			if (inp[i] - inp[i - 1] > 1)
				can = false;
		if (can) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}

