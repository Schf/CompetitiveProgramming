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
	cout.tie (0);
	ll i, j, n, m, x, y;
	cin >> n >> m >> x >> y;
	vector <pair <ll, ll>> out;
	out.reserve (n*m + 1);
	if (n&1)
	{
		if (m&1)
		{
			for (i = 0; i < n - 2; ++i)
				if (i&1) for (j = m - 1; j >= 0; --j) out.push_back ({i, j});
				else for (j = 0; j < m; ++j) out.push_back ({i, j});
			for (j = m - 1; j > 0; j -= 2)
				out.push_back ({n - 2, j}),
				out.push_back ({n - 1, j}),
				out.push_back ({n - 1, j - 1}),
				out.push_back ({n - 2, j - 1});
			out.push_back ({n - 2, 0}),
			out.push_back ({n - 1, 0}),
			out.push_back ({0, 0});
		}
		else
		{
			for (i = 0; i < n - 2; ++i) out.push_back ({i, 0});
			for (i = n - 3; i >= 0; --i)
				if (i&1) for (j = m - 1; j >= 1; --j) out.push_back ({i, j});
				else for (j = 1; j < m; ++j) out.push_back ({i, j});
			for (j = m - 1; j > 0; j -= 2)
				out.push_back ({n - 1, j}),
				out.push_back ({n - 2, j}),
				out.push_back ({n - 2, j - 1}),
				out.push_back ({n - 1, j - 1});
			out.push_back ({0, 0});
		}
	}
	else
	{
		for (i = 0; i < n; ++i)
			if (i&1) for (j = m - 1; j >= 0; --j) out.push_back ({i, j});
			else for (j = 0; j < m; ++j) out.push_back ({i, j});
		out.push_back ({0, 0});
	}
	trav (p, out)
		cout << (p.f + x - 1) % n + 1 << ' ' << (p.s + y - 1) % m + 1 << '\n';

	return 0;
}


