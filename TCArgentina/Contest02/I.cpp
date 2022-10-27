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
const ll bs = 340;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, m;
	cin >> n >> m;
	vector <ll> A (n), B (n), bucs (n/bs + 1, -1);
	trav (a, A) cin >> a;
	trav (b, B) cin >> b;
	for (ll qq = 0; qq < m; ++qq)
	{
		ll mode;
		cin >> mode;
		if (mode == 1)
		{
			ll x, y, k;
			cin >> x >> y >> k;
			--x, --y;
			if (bucs[y/bs] >= 0)
				for (i = 0; i < bs; ++i)
					B[(y/bs)*bs + i] = A[bucs[y/bs] + i];
			bucs[y/bs] = -1;
			if (bucs[(y+k-1)/bs] >= 0)
				for (i = 0; i < bs; ++i)
					B[((y+k-1)/bs)*bs + i] = A[bucs[(y+k-1)/bs] + i];
			bucs[(y+k-1)/bs] = -1;
			for (i = 0; y + i < (y/bs + 1)*bs && i < k; ++i)
				B[y + i] = A[x + i];
			for (j = y/bs + 1; (j+1)*bs-y < k; ++j, i += bs)
				bucs[j] = x + i;
			for (; i < k; ++i)
				B[y + i] = A[x + i];
		}
		else
		{
			ll y;
			cin >> y;
			--y;
			if (bucs[y/bs] >= 0)
				for (i = 0; i < bs; ++i)
					B[(y/bs)*bs + i] = A[bucs[y/bs] + i];
			bucs[y/bs] = -1;
			cout << B[y] << '\n';
		}
	}

	return 0;
}

