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
	ll i, j, n, h, w, k;
	cin >> h >> w >> k;
	vector <vector <bool>> mat (h, vector <bool> (w));
	for (i = 0; i < h; ++i)
	{
		string s;
		cin >> s;
		for (j = 0; j < w; ++j)
			mat[i][j] = (s[j] == '.');
	}
	ll ans = 0;
	for (ll hi = 0; hi < 1 << h; ++hi)
		for (ll wj = 0; wj < 1 << w; ++wj)
		{
			ll cur_k = 0;
			for (i = 0; i < h; ++i)
				for (j = 0; j < w; ++j)
					if ((hi & 1<<i) && (wj & 1<<j) && !mat[i][j])
						++cur_k;
			if (cur_k == k) ++ans;
		}
	cout << ans << '\n';

	return 0;
}

