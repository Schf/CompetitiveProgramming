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
	vector <ll> inp (n);
	trav (a, inp) cin >> a;
	ll ans = 0;
	for (i = 0; i < n; ++i)
		for (j = i + 1; j < n; ++j)
			for (int k = j + 1; k < n; ++k)
				if (inp[i] != inp[j] && inp[i] != inp[k] && inp[j] != inp[k])
				{
					vector <ll> aux = {inp[i], inp[j], inp[k]};
					sort (aux.begin (), aux.end ());
					if (aux[0] + aux[1] > aux[2])
						++ans;
				}
	cout << ans << '\n';

	return 0;
}

