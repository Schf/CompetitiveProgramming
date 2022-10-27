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
	ll i, j, n;
	cin >> n;
	vector <ll> inp (n);
	trav (a, inp) cin >> a;
	if (n <= 2)
	{
		cout << n << '\n';
		return 0;
	}
	vector <pair <ll, ll>> highs = {{1, 0}};
	for (i = 1; i < n; ++i)
		if (inp[i] > inp[i - 1])
			++highs[highs.size () - 1].f;
		else highs.push_back ({1, i});
	//trav (p, highs) cout << p.f << ' ' << p.s << " | ";
	//cout << '\n';
	if (highs.size () == 1)
	{
		cout << highs[0].f << '\n';
		return 0;
	}
	ll ans = highs[0].f + 1;
	if (highs[1].s == 1 || inp[highs[1].s] - 1 > inp[highs[1].s - 2] ||
			(highs[1].f > 1 && inp[highs[1].s + 1] - 1 > inp[highs[1].s - 1]))
		ans = highs[0].f + highs[1].f;
	else ans = max (ans, highs[1].f + 1);
	for (i = 2; i < highs.size (); ++i)
	{
		ans = max (ans, highs[i].f + 1);
		if (inp[highs[i].s] - 1 > inp[highs[i].s - 2] ||
				(highs[i].f > 1 && inp[highs[i].s + 1] - 1 > inp[highs[i].s - 1]))
			ans = max (ans, highs[i].f + highs[i - 1].f);
	}
	cout << ans << '\n';

	return 0;
}

