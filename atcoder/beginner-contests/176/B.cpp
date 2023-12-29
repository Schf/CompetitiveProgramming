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
	ll i, j, n;
	string s;
	cin >> s;
	ll ans = 0;
	for (i = 0; i < s.size (); ++i)
		ans += s[i] - '0';
	if (ans%9 == 0) cout << "Yes\n";
	else cout << "No\n";


	return 0;
}

