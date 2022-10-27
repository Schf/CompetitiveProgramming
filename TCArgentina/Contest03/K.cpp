#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+7+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	cin >> n;
	set <ll> goods;
	for (i = 1; i < 2*MAXN; i <<= 1)
		goods.insert (i - 1);
	if (goods.find (n) != goods.end ())
	{
		cout << 0 << '\n';
		return 0;
	}
	vector <ll> inst;
	while (true)
	{
		for (i = 1, j = 0; i < n && !(n&i); i <<= 1, ++j);
		inst.push_back (j);
		n ^= i - 1;
		if (goods.find (n) != goods.end ()) break;
		n += 1;
	}
	cout << inst.size () * 2 - 1 << '\n';
	trav (a, inst) cout << a << ' ';
	cout << '\n';

	return 0;
}

