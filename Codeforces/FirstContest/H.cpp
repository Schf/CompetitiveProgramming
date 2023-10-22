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

vector <ll> inp;

struct gt
{
	bool operator () (ll i, ll j)
	{
		return inp[i] < inp[j];
	}
};

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, k;
	cin >> n >> k;
	inp.resize (n);
	trav (a, inp) cin >> a;
	set <ll, gt> mxs, mns;
	for (i = 0; i < n; ++i)
	{
		mxs.insert (i), mns.insert (i);
		if (mxs.size () > k) mxs.erase (mxs.begin ());
		if (mns.size () > k) mns.erase (--mns.end ());
	}
	while (mxs.size () > k)
		mxs.erase (mxs.begin ());
	while (mns.size () > k)
		mns.erase (--mns.end ());
	vector <ll> mxv, mnv;
	trav (a, mxs) mxv.push_back (a);
	trav (a, mns) mnv.push_back (a);
	sort (mxv.begin (), mxv.end ());
	sort (mnv.begin (), mnv.end ());
	trav (a, mxv) cout << a << ' ';
	cout << '\n';
	trav (a, mnv) cout << a << ' ';
	cout << '\n';
	ll mn, mx;
	for (i = j = 0; i < mxv.size () - 1; ++i)
		for (mn = INF; j < mxv[i + 1]; ++j)
			mn = min (mn, inp[j]);

	return 0;
}


