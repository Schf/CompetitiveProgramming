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
	vector <vector <ll>> inp (3, vector <ll> ());
	for (i = 0; i < n; ++i)
		cin >> j, inp[j - 1].push_back (i + 1);
	sort (inp.begin (), inp.end (), [] (auto & v1, auto & v2)
	{
		return v1.size () < v2.size ();
	});
	cout << inp[0].size () << '\n';
	for (i = 0; i < inp[0].size (); ++i)
		cout << inp[0][i] << ' ' << inp[1][i] << ' ' << inp[2][i] << '\n';

	return 0;
}

