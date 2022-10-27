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
	ll i, j, n, x, y;
	cin >> n;
	while (cin >> n >> x >> y)
	{
		vector <ll> divs;
		for (i = 1; i <= y - x; ++i)
			if ((y - x)%i == 0)
				divs.push_back (i);
		//trav (a, divs) cout << a << ' ';
		//cout << "| ";
		vector <ll> out (n, INF);
		trav (d, divs)
		{
			if ((y-x)/d + 1 > n) continue;
			vector <ll> curout (n);
			curout[n - 1] = y;
			for (i = n - 2; i >= 0; --i)
				curout[i] = curout[i + 1] - d;
			for (i = 0; curout[0] <= 0; ++i)
				curout[0] += d;
			for (j = 1; j < n; ++j)
				curout[j] += i*d;
			if (out.back () > curout.back ())
				out = curout;
		}
		trav (a, out) cout << a << ' ';
		cout << '\n';
	}

	return 0;
}

