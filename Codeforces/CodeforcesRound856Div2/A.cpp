#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto &a : A)
#define f first
#define s second

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

ll MOD = 1e+9 + 7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5 + 7;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll i, j, n, t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<string> vs(2*n - 2);
		for (i = 0; i < 2*n - 2; ++i)
			cin >> vs[i];
		
		sort (vs.begin (), vs.end (), [&] (string & a, string & b)
		{
			return a.size () > b.size ();
		});
		if (vs[0].substr(1, n-2) != vs[1].substr(0, n-2))
			swap (vs[0], vs[1]);

		string s = vs[0].substr(0, n-1) + vs[1][n-2];
		for (j = 1, i = 0; i < s.size ()/2; ++i)
			j = j&&(s[i]==s[s.size () - i - 1]);
		if (j) cout << "YES\n";
		else cout << "NO\n";

	}

	return 0;
}
