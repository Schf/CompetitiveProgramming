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
	vector <ll> inp (n), freq (n + 1, 0);
	trav (a, inp) cin >> a;
	ll big = n + 1;
	trav (a, inp)
		if (a == big - 1)
		{
			for (i = big - 1, freq[a] = 1; i > 0 && freq[i]; big = i--)
				cout << i << ' ';
			cout << '\n';
		}
		else
			freq[a] = 1, cout << '\n';
	if (big - 1 > 0)
	{
		for (i = big - 1; i > 0 && freq[i]; --i)
			cout << i << ' ';
		cout << '\n';
	}

	return 0;
}

