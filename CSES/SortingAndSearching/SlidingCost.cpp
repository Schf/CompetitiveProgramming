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
ll sub, sum;

void insert (int num)
{
	if (!sm.size ())
		sub = num,
		sum = 0,
		sm.insert (num);
	else if (sm.size () == bg.size ())
		if (num < *(bg.begin ()))
			sub += num,
			sm.insert (num);
		else
			sub += *(bg.begin ()),
			sm.insert (*(bg.begin ())),
			sum -= *(bg.begin ()),
			bg.erase (bg.begin ()),
			sum += num,
			bg.insert (num);
	else
		if (num > *(sm.rbegin ()))
			sum += num,
			bg.insert (num);
		else
			sum += *(sm.rbegin ()),
			bg.insert (*(sm.rbegin ())),
			sub -= *(sm.rbegin ()),
			sm.erase (--(sm.end ())),
			sub += num,
			sm.insert (num);
}

void remove (int num)
{
	if (num > *(sm.rbegin ()))
		sum -= num,
		bg.erase (bg.find (num));
	else
		sub -= num,
		sm.erase (sm.find (num));
	while (sm.size () < bg.size ())
		sub += *(bg.begin ()),
		sm.insert (*(bg.begin ())),
		sum -= *(bg.begin ()),
		bg.erase (bg.begin ());
	while (sm.size () - 1 > bg.size ())
		sum += *(sm.rbegin ()),
		bg.insert (*(sm.rbegin ())),
		sub -= *(sm.rbegin ()),
		sm.erase (--(sm.end ()));
}

ll cost ()
{
	return sum - bg.size () * *(sm.rbegin ()) + sm.size () * *(sm.rbegin ()) - sub;
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
		cout << cost () << ' ';
		for (i = k; i < n; ++i)
		{
			insert (inp[i]);
			remove (inp[i - k]);
			cout << cost () << ' ';
		}
		cout << '\n';
	}

	return 0;
}

