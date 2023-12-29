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
	vector <string> inp (n);
	trav (s, inp) cin >> s;
	vector <ll> lim (n);
	for (i = 0; i < n; ++i)
		lim[i] = inp[i].size ();
	for (i = n - 2; i >= 0; --i)
	{
		for (j = 0; j < lim[i] && j < lim[i + 1]; ++j)
			if (inp[i][j] < inp[i + 1][j]) break;
			else if (inp[i][j] > inp[i + 1][j])
			{
				lim[i] = j;
				break;
			}
		if (lim[i] > lim[i + 1] && j == lim[i + 1])
			lim[i] = lim[i + 1];
	}
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < lim[i]; ++j)
			cout << inp[i][j];
		cout << '\n';
	}

	return 0;
}

