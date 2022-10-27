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
	ll tc = 1;
	cin >> tc;
	while (tc--)
	{
		ll i, j, n, ans;
		string s;
		cin >> n >> s;
		bool can = true;
		for (i = j = ans = 0; i < n; ++i)
			if (s[i] == '(') ++j;
			else ans = min (ans, --j);
		
		cout << abs (ans) << '\n';
	}
	

	return 0;
}

