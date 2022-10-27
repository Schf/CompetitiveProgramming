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
		vector <ll> freq (n + 1), ffreq (n + 1);
		for (i = 0; i < n; ++i)
			cin >> j, ++freq[j];
		trav (a, freq)
			++ffreq[a];
		ll hf = *max_element (freq.begin (), freq.end ());
		n -= ffreq[hf];
		cout << n/(hf - 1) - 1 << '\n';
	}

	return 0;
}

