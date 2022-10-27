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
		int i, j, n, a, b, p;
		cin >> a >> b >> p;
		int price['B' + 1];
		price['A'] = a;
		price['B'] = b;
		string s;
		cin >> s;
		vector <ll> cost (s.size ());
		for (i = 0; i < cost.size () - 1; i = j)
		{
			cost[i] = price[s[i]];
			for (j = i + 1; j < s.size () && s[j - 1] == s[j]; ++j)
				cost[j] = price[s[j]];
		}
		cost[cost.size () - 1] = 0;
		for (i = cost.size () - 3; i >= 0; --i)
			cost[i] = s[i] == s[i + 1] ? (cost[i + 1]) : (cost[i] + cost[i + 1]);
		for (i = 0; i < cost.size (); ++i)
			if (p >= cost[i])
				break;
		cout << i + 1 << '\n';
	}

	return 0;
}

