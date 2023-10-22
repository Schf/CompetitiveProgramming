#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

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
	ll tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n, x, cur, ans = 0;
		cin >> n >> x;
		vector <ll> inp (n);
		trav (a, inp) cin >> a;
		ans = (inp[0] == x);
		for (i = 0, j = 1, cur = inp[0]; j < n;)
		{
			if (cur == x) cur -= inp[i++], cur += inp[j++];
			else if (cur < x) cur += inp[j++];
			else if (i < j - 1) cur -= inp[i++];
			else cur = inp[j++], ++i;
			
			if (cur == x) ++ans;
		}
		for (cur -= inp[i++]; i < j; ++i)
		{
			if (cur == x) ++ans;
			cur -= inp[i];
		}
		cout << ans << '\n';
	}

	return 0;
}

