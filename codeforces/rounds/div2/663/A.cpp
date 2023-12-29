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
		vector <ll> out (n);
		iota (out.begin (), out.end (), 1);
		trav (a, out) cout << a << ' ';
		cout << '\n';
	}

	return 0;
}

