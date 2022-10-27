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
	vector <ll> inp;
	while (cin >> n) inp.push_back (n);
	sort (inp.begin (), inp.end ());
	cout << inp[0];
	for (i = 1; i < inp.size (); ++i)
		cout << '+' << inp[i];
	cout << '\n';

	return 0;
}

