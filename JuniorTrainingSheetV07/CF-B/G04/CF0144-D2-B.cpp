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
	ll i, j, n, xa, ya, xb, yb;
	cin >> xa >> ya >> xb >> yb >> n;
	vector <vector <ll>> inp (n, vector <ll> (3)),
			generals;
	for (i = 0; i < n; ++i)
		for (j = 0; j < 3; ++j)
			cin >> inp[i][j];
	for (i = min (xa, xb); i <= max (xa, xb); ++i)
		generals.push_back ({i, ya}),
		generals.push_back ({i, yb});
	for (i = min (ya, yb) + 1; i <= max (ya, yb) - 1; ++i)
		generals.push_back ({xa, i}),
		generals.push_back ({xb, i});
	ll ans = 0;
	//trav (rad, inp)
	//	cout << rad[0] << ' ' << rad[1] << ' ' << rad[2] << " | ";
	//cout << '\n';
	trav (general, generals)
	{
		//cout << general[0] << ' ' << general[1] << " | ";
		bool cold = true;
		trav (rad, inp)
		{
			ll dx = rad[0] - general[0];
			ll dy = rad[1] - general[1];
			if (dx*dx + dy*dy <= rad[2]*rad[2])
				cold = false;
		}
		ans += cold;
	}
	//cout << '\n';
	cout << ans << '\n';

	return 0;
}

