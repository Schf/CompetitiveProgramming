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
	ll i, j, n, p = 0;
	string s;
	cin >> s;
	ll ans = 0;
	vector <ll> sll (s.size ());
	for (i = 0; i < s.size (); ++i)
		sll[i] = s[i] - 'a';
	trav (a, sll)
		ans += min ((p - a + 26)%26, (a - p + 26)%26), p = a;
	cout << ans << '\n';

	return 0;
}

