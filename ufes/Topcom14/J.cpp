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

vector <pair <ll, ll>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

inline bool valid (ll a, ll b, vector <vector <ll>> & mp)
{
	return 0 <= a && a < mp.size () && 0 <= b && b <= mp[0].size () &&
			mp[a][b] == 0;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n, r, c;
	while (cin >> r >> c)
	{
		vector <vector <ll>> mp (r, vector <ll> (c));
		vector <pair <ll, ll>> src, tgt;
		for (i = 0; i < r; ++i)
		{
			string s;
			cin >> s;
			for (j = 0; j < s.size (); ++j)
				mp[i][j] = ((s[j] == '.') ? (0) : (-1));
		}
	}

	return 0;
}

