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

bool pal (string s)
{
	bool ans = true;
	for (int i = 0; i < s.size () / 2 && ans; ++i)
		ans = (s[i] == s[s.size () - i - 1]);
	return ans;
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll tc = 1; //cin >> tc;
	while (tc--)
	{
		ll i, j, n;
		string s;
		cin >> s;
		if (pal (s) &&
				pal (s.substr (0, s.size ()/2)) &&
				pal (s.substr ((s.size () + 1)/2, s.size ()/2)))
			cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}


