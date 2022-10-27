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
	while (tc--)
	{
		ll i, j, n, x;
		cin >> n >> x;
		vector <ll> freq (1000, 0);
		for (i = 0; i < n; ++i)
			cin >> j, freq[j] = 1;
		for (i = 1; x > 0; ++i)
			if (freq[i] == 0) freq[i] = 1, --x;
		for (; freq[i] > 0; ++i);
		cout << --i << '\n';
	}
	

	return 0;
}

