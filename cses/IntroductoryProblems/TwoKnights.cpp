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

inline bool valid (int i, int j, int k)
{
	return 0 <= i && i < k && 0 <= j && j < k;
}

vector <pair <ll, ll>> posr =
	{{-2, -1}, {-1, -2}, {2, -1}, {1, -2}};
vector <pair <ll, ll>> posd =
	{{-2, -1}, {-1, -2}, {-2, 1}, {-1, 2}};

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		cin >> n;
		for (ll k = 1, sub = 0; k <= n; ++k)
		{
			for (i = 0; i < k; ++i)
			{
				for (j = 0; j < 4; ++j)
				{
					if (valid (i + posr[j].f, k - 1 + posr[j].s, k - 1)) ++sub;
					if (valid (k - 1 + posd[j].f, i + posd[j].s, k - 1)) ++sub;
				}
			}
			cout << (k*k)*(k*k - 1)/2 - sub << '\n';
		}
	}
 
	return 0;
}

