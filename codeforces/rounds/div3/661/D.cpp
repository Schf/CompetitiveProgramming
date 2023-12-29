#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1;
	cin >> tc;
	ll n;
	while (cin >> n)
	{
		ll i, j;
		string s;
		cin >> s;
		ll b0, b1;
		vector <ll> ans (s.size ());
		for (i = b0 = b1 = 0; i < s.size (); ++i)
		{
			b0 += (s[i] == s[0]);
			b1 += (s[i] != s[0]);
			ans[i] = b0 - b1 + (s[i] != s[0]);
		}
		ll add = *min_element (ans.begin (), ans.end ());
		trav (a, ans) a -= add - 1;
		cout << *max_element (ans.begin (), ans.end ()) << '\n';
		trav (a, ans) cout << a << ' ';
		cout << '\n';
	}

	return 0;
}

