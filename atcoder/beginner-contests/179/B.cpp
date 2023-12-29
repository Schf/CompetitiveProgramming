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
	ll i, j, n;
	cin >> n;
	vector <pair <ll, ll>> inp (n);
	trav (p, inp) cin >> p.f >> p.s;
	bool ok = false;
	for (i = 0; i + 2 < n; ++i)
	{
		bool cur_ok = true;
		for (j = 0; j < 3; ++j)
			if (inp[i + j].f != inp[i + j].s)
				cur_ok = false;
		ok = ok || cur_ok;
	}
	if (ok) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}

