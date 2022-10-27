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
	ll i, j, n, s, d;
	s = d = 0;
	cin >> n;
	deque <ll> inp;
	for (i = 0; i < n; ++i)
		cin >> j, inp.push_back (j);
	for (i = 0; !inp.empty (); ++i)
		if (i&1)
			if (inp.front () > inp.back ())
				d += inp.front (), inp.pop_front ();
			else d += inp.back (), inp.pop_back ();
		else
			if (inp.front () > inp.back ())
				s += inp.front (), inp.pop_front ();
			else s += inp.back (), inp.pop_back ();
	cout << s << ' ' << d << '\n'; 


	return 0;
}

