#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

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

multiset <ll> sm, bg;

void insert (int num)
{
	if (!sm.size ())
		sm.insert (num);
	else if (sm.size () == bg.size ())
		if (num < *(bg.begin ()))
			sm.insert (num);
		else
			sm.insert (*(bg.begin ())),
			bg.erase (bg.begin ()),
			bg.insert (num);
	else
		if (num > *(sm.rbegin ()))
			bg.insert (num);
		else
			bg.insert (*(sm.rbegin ())),
			sm.erase (--(sm.end ())),
			sm.insert (num);
}

void remove (int num)
{
	if (num > *(sm.rbegin ())) bg.erase (bg.find (num));
	else sm.erase (sm.find (num));
	while (sm.size () < bg.size ())
		sm.insert (*(bg.begin ())),
		bg.erase (bg.begin ());
	while (sm.size () - 1 > bg.size ())
		bg.insert (*(sm.rbegin ())),
		sm.erase (--(sm.end ()));
}

ll median ()
{
	return *(sm.rbegin ());
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n, k;
		cin >> n >> k;
		vector <ll> inp (n);
		trav (a, inp) cin >> a;
		for (i = 0; i < k; ++i)
			insert (inp[i]);
		cout << median () << ' ';
		for (i = k; i < n; ++i)
		{
			insert (inp[i]);
			remove (inp[i - k]);
			cout << median () << ' ';
		}
		cout << '\n';
	}

	return 0;
}

