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
	ll tc;
	cin >> tc;
	map <ll, ll> ref;
	ll i, j, n;
	for (i = 0, j = 1; i < MAXN; ++i)
		ref[j] = i,
		j += 2*(i + 1);
	cout << ref.rbegin ()->f << ' ' << ref.rbegin ()->s << '\n';
	while (tc--)
	{
		ll i, j, n, r, l;
		cin >> n >> r >> l;
		for (; r <= l; ++r)
			for (i = 1, j = r; j > 0; ++i)
				
	}

	return 0;
}

