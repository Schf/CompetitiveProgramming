#pragma GCC optimize ("O2")
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-label"
#pragma GCC diagnostic ignored "-Wsign-compare"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define trav(a, A) for (auto & a : A)
#define all(a) (a).begin (), (a).end ()
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+6+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; cin >> tc;
	while (tc--)
	{
		int i, j;
		ll n, d;
		cin >> n >> d;
		ll mn = 0;
		for (i = 1; i < n; i = (i << 1) | 1)
			mn += (i - (i >> 1))*(__builtin_popcount (i) - 1);
		i >>= 1;
		mn += (n - i)*__builtin_popcount (i);
		ll mx = (n - 1)*n/2;
		if (d < mn || mx < d)
		{
			cout << "NO\n";
			continue;
		}
		vector <int> prnt (n), cldc (n, 1), bad (n, 0), dpth (n);
		iota (prnt.begin (), prnt.end (), -1);
		iota (dpth.begin (), dpth.end (), 0);
		cldc[cldc.size () - 1] = 0;
		ll ans = mx;
		while (ans > d)
		{
			int v = -1;
			for (i = 0; i < n; ++i)
				if (!bad[i] && cldc[i] == 0 && (v == -1 || dpth[v] > dpth[i]))
					v = i;
			int p = -1;
			for (i = 0; i < n; ++i)
				if (cldc[i] < 2 && dpth[i] < dpth[v] - 1 &&
						(p == -1 || dpth[p] < dpth[i]))
					p = i;
			if (p == -1)
			{
				bad[v] = 1;
				continue;
			}
			--cldc[prnt[v]];
			--dpth[v];
			++cldc[p];
			prnt[v] = p;
			--ans;
		}
		cout << "YES\n";
		for (i = 1; i < n; ++i) cout << prnt[i] + 1 << ' ';
		cout << '\n';
	}

	return 0;
}


