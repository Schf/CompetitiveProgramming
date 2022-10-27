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
	int tc;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n, mx = 1;
		cin >> n;
		vector <ll> inp (n), cor (n, 0);
		trav (a, inp) cin >> a;
		cor[0] = 1;
		for (i = 1; i < n; ++i)
			if (inp[i - 1] == inp[i]) cor[i] = cor[i - 1];
			else if (cor[i - 1] > 1) cor[i] = 1;
			else cor[i] = mx = 2;
		if (inp[n - 1] != inp[0] && cor[n - 1] == cor[0])
			for (i = n - 2, cor[n - 1] = 2; i >= 0; --i)
				if (inp[i] == inp[i + 1] || cor[i] != cor[i + 1]) break;
				else cor[i] = 3 - cor[i + 1];
		if (inp[n - 1] != inp[0] && cor[n - 1] == cor[0])
			cor[n - 1] = mx = 3;
		cout << mx << '\n';
		trav (a, cor) cout << a << ' ';
		cout << '\n';
	}

	return 0;
}


