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

bool count (list <pair <ll, ll>> & A, list <pair <ll, ll>> & B)
{
	ll i, j;
	trav (a, A) a.f = 0;
	trav (b, B) b.f = 0;
	trav (a, A)
		trav (b, B)
			if (b.s%a.s == 0)
				++a.f, ++b.f;
	auto itta = A.begin (), ittb = B.begin ();
	for (auto itt = A.begin (); itt != A.end (); ++itt)
		if (itta->f < itt->f) itta = itt;
	for (auto itt = B.begin (); itt != B.end (); ++itt)
		if (ittb->f < itt->f) ittb = itt;
	if (itta->f == 0 && ittb->f == 0) return false;
	if (itta->f > ittb->f) { A.erase (itta); return true; }
	else { B.erase (ittb); return true; }
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc;
	cin >> tc;
	for (ll tcc = 0; tcc < tc; ++tcc)
	{
		ll i, j, n, m;
		cin >> n;
		list <pair <ll, ll>> A (n);
		trav (p, A) cin >> p.s;
		cin >> m;
		list <pair <ll, ll>> B (m);
		trav (p, B) cin >> p.s;
		ll ans = 0;
		while (count (A, B)) ++ans;
		cout << "Caso #" << tcc + 1 << ": " << ans << '\n';
	}

	return 0;
}


