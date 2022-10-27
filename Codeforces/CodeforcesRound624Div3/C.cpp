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
		int i, j, n, m;
		string s;
		cin >> n >> m >> s;
		vector <vector <ll>> sumcount (s.size () + 1, vector <ll> ('z' + 1, 0));
		for (i = 1; i <= s.size (); ++i)
		{
			for (j = 'a'; j <= 'z'; ++j)
				sumcount[i][j] += sumcount[i - 1][j] + (s[i - 1] == j ? 1 : 0);
		}
		vector <int> mist (m);
		trav (a, mist) cin >> a;
		vector <ll> ans ('z' + 1, 0);
		trav (a, mist)
		{
			for (j = 'a'; j <= 'z'; ++j)
				ans[j] += sumcount[a][j];
		}
		for (i = 'a'; i <= 'z'; ++i)
			cout << ans[i] + sumcount [s.size ()][i] << ' ';
		cout << '\n';
	}

	return 0;
}


