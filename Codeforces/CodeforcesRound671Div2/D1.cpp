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
	vector <ll> inp (n), out (n);
	trav (a, inp) cin >> a;
	sort (inp.begin (), inp.end ());
	for (i = 0; i < n; i += 2)
		out[i] = inp[i/2 + n/2];
	for (i = 1; i < n; i += 2)
		out[i] = inp[i/2];
	cout << (n-1)/2 << '\n';
	trav (a, out) cout << a << ' ';
	cout << '\n';

	return 0;
}

